#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/poll.h>

#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LINE 1024
#define OPEN_MAX 16
#define SERVER_PORT 10001

int main(int argc, char* argv[]) {
    
    int i, max_index, listen_fd, connect_fd, sock_fd, epoll_fd, nfds;
    int n;
    char buf[MAX_LINE];
    struct epoll_event ev, events[20];
    socklen_t cli_len;
    struct pollfd client[OPEN_MAX];
    struct sockaddr_in client_addr, server_addr;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_addr, 0 , sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(listen_fd, (struct sockaddr_in*)&server_addr, sizeof(server_addr));
    listen(listen_fd,10);

    epoll_fd = epoll_create(256); 
    ev.data.fd = listen_fd;
    ev.events = EPOLLIN | EPOLLET;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &ev);

    while(1) {
        nfds = epoll_wait(epoll_fd, events, 20, 500);
        for(i = 0; i < nfds; ++i){
            if(listen_fd == events[i].data.fd) {
                cli_len = sizeof(client_addr);
                connect_fd = accept(listen_fd, (struct sockaddr*) &client_addr, &cli_len);
                if(0 > connect_fd) {
                    perror("connect_fd < 0");
                    exit(1);
                }
                ev.data.fd = connect_fd;
                ev.events = EPOLLIN | EPOLLET;
                epoll_ctl(epoll_fd, EPOLL_CTL_ADD, connect_fd, &ev);
            }
            else if(events[i].events & EPOLLIN) {
                if(0 > (sock_fd = events[i].data.fd)) {
                    continue;
                }
                n = recv(sock_fd, buf, MAX_LINE, 0);
                if(0 >= n) {
                    close(sock_fd);
                    events[i].data.fd = -1;
                }
                else {
                    buf[n] = '\0';
                    fprintf(stdout, "socket %d said: %s\n", sock_fd, buf);
                    ev.data.fd = sock_fd;
                    ev.events = EPOLLOUT | EPOLLET;
                    epoll_ctl(epoll_fd, EPOLL_CTL_MOD, connect_fd, &ev);
                }
            }
            else if(events[i].events & EPOLLOUT) {
                sock_fd = events[i].data.fd;
                send(sock_fd, "Hello!", 7, 0);

                ev.data.fd = sock_fd;
                ev.events = EPOLLIN | EPOLLET;
                epoll_ctl(epoll_fd, EPOLL_CTL_MOD, sock_fd, &ev);
            }
            else {
                fprintf(stderr, "this is not avaliable.\n");
            }
        }
    }

    close(epoll_fd);
    return 0;
}