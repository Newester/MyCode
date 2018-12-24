#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <poll.h>

#define INFTIM -1
#define POLL_RDNORM 0x040
#define POLL_RDBAND 0x080
#define POLL_WRNORM 0x100
#define POLL_WRBAND 0x200

#define MAX_LINE 1024
#define OPEN_MAX 16
#define SERVER_PORT 10001

int main(int argc, char* argv[]) {
    int i, max_index, listen_fd, connect_fd, sock_fd;
    int nready;
    int n;
    char buf[MAX_LINE];
    socklen_t cli_len;
    struct pollfd client[OPEN_MAX];

    struct sockaddr_in cli_addr, server_addr;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr =htonl(INADDR_ANY);

    bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(listen_fd, 10);
    client[0].fd = -1;
    for(i = 1; i < OPEN_MAX; ++i) {
        client[i].fd = -1;
    }
    max_index = 0;

    while(1) {
        nready = poll(client, max_index+1, INFTIM);
        if(client[0].revents & POLL_RDNORM) {
            cli_len = sizeof(cli_addr);
            connect_fd = accept(listen_fd, (struct sockaddr*)&cli_addr, &cli_len);
            for(i = 0; i < OPEN_MAX; ++i) {
                if(0 > client[i].fd) {
                    client[i].fd = connect_fd;
                    client[i].revents = POLL_RDNORM;
                    break;
                }
            }
            if(OPEN_MAX == i) {
                fprintf(stderr, "too many clients!\n");
            }
            if(i > max_index) {
                max_index = i;
            }
            nready--;
            if(0 >= nready) {
                continue;
            }
        }

        for(i = 1; i < max_index; ++i) {
            if(0 > client[i].fd) {
                continue;
            }
            sock_fd = client[i].fd;
            if(client[i].revents & (POLL_RDNORM|POLLERR)) {
                n = read(client[i].fd, buf, MAX_LINE);
                if(0 >= n) {
                    close(client[i].fd);
                    client[i].fd = -1;
                }
                else {
                    buf[n] = '\0';
                    fprintf(stderr, "socket %d said: %s\n", sock_fd, buf);
                    write(sock_fd, buf, n);
                }
                nready--;
                if(0 >= nready) {
                    break;
                }
            }
        }
    }
    return 0;
}