#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8000
#define MAX_LINE 4096

int main(int argc, char *argv[]) {
    int socket_fd, n, recv_len;
    char recv_line[4096], send_line[4096];
    char buf[MAX_LINE];
    struct sockaddr_in serverAddr;

    if(2 != argc) {
        printf("usage: ./client <ipaddress>\n");
        exit(0);
    }

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(0 > socket_fd) {
        printf("create socket error: %s(errno:%d)\n", strerror(errno), errno);
        exit(0);
    }

    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    
    if(0 >= inet_pton(AF_INET, argv[1], &serverAddr.sin_addr)) {
        printf("inet_pton error for %s\n", argv[1]);
        exit(0);
    }

    if(0 > connect(socket_fd, (struct sockaddr*)&serverAddr, sizeof(serverAddr))) {
        printf("connect error: %s(errno:%d)\n", strerror(errno), errno);
        exit(0);
    }

    printf("send message to server:\n");
    fgets(send_line, 4096, stdin);
    if(0 > send(socket_fd, send_line, strlen(send_line), 0)) {
        printf("send message error: %s(errno:%d)\n", strerror(errno), errno);
        exit(0);
    }

    recv_len = recv(socket_fd, buf, MAX_LINE, 0);
    if(-1 == recv_len) {
        perror("recv error");
        exit(1);
    }

    buf[recv_len] = '\0';
    printf("recived: %s", buf);

    close(socket_fd);
    exit(0);
}