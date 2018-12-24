#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>

const static int MAX_LINE = 1024;
const static int SERVER_PORT = 10001;

int main(int argc, char* argv[]) {
    int index, maxindex, max_fd, listen_fd, connect_fd, sock_fd;

    int nready, client[FD_SETSIZE];
    
    int n;

    fd_set rset, allset;
    char buf[MAX_LINE];
    socklen_t client_len;
    struct sockaddr_in cli_addr, server_addr;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    memset(&server_addr, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(listen_fd, 100);

    max_fd = listen_fd;

    maxindex = -1;

    for(index = 0; index < FD_SETSIZE; ++index) {
        client[index] = -1;
    }

    FD_ZERO(&allset);
    FD_SET(listen_fd, &allset);

    while(1) {
        rset = allset;
        nready = select(max_fd+1, &rset, NULL, NULL, NULL);
        if(FD_ISSET(listen_fd, &rset)) {
            client_len = sizeof(cli_addr);
            connect_fd = accept(listen_fd, (struct sockaddr*)&cli_addr, &client_len);
            for(index = 0; index < FD_SETSIZE; ++index) {
                if(0 > client[index]) {
                    client[index] = connect_fd;
                    break;
                }
            }

            if(index == FD_SETSIZE) {
                fprintf(stderr, "Too many clients, over stack.\n");
                return -1;
            }
            FD_SET(connect_fd,&allset);
            if(connect_fd > max_fd) {
                max_fd = connect_fd;
            }
            if( index > maxindex) {
                maxindex = index;
            }
            if(1 >= nready) {
                continue;
            }
            else {
                nready--;
            }
        }

        for(index = 0; index < maxindex; ++index) {
            if(0 > client[index]) {
                continue;
            }
            sock_fd = client[index];
            if(FD_ISSET(sock_fd, &rset)) {
                n = read(sock_fd, buf, MAX_LINE);
                if(0 == n) {
                    close(sock_fd);
                    FD_CLR(sock_fd,&allset);
                    client[index] = -1;
                }
                else {
                    buf[n] = '\0';
                    fprintf(stdout,"Socket %d said: %s\n", sock_fd, buf);
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