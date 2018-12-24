#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define DEFAULT_PORT 8000
#define MAX_LINE 4096

int main(int argc, char* argv[]) {
    int socket_fd, connect_fd;
    struct sockaddr_in serverAddr;
    char buf[4096];
    int n = 0;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(-1 == socket_fd) {
        printf("create socket error: %s (errno:%s)\n", strerror(errno), errno);
        exit(0);
    }
    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(DEFAULT_PORT);

    if(-1 == bind(socket_fd, (struct sockaddr* )&serverAddr, sizeof(serverAddr))) {
        printf("bind socket error: %s(errno: %d)\n", strerror(errno), errno);
        exit(0);
    }
    
    if(-1 == listen(socket_fd, 10)) {
        printf("listen socket error:%s (errno:%d)\n", strerror(errno), errno);
        exit(0);
    }
    
    printf("========== waiting for client's request =========\n");

    while(1) {
        connect_fd = accept(socket_fd, (struct sockaddr*)NULL, NULL);
        if(-1 == connect_fd) { 
            printf("accept socket error: %s(errno:%d)\n", strerror(errno), errno);
            continue;
        }

        n = recv(connect_fd, buf, MAX_LINE, 0);

        if(!fork()) {
            if(-1 == send(connect_fd, "Welcome to connected !\n", 24, 0)) {
                perror("send error");
            }
            close(connect_fd);
            exit(0);
        }

        if(0 < n) {
            buf[n] = '\0';
            printf("recv message from client: %s\n", buf);
        }
        close(connect_fd);
        
    }
    close(socket_fd);
}