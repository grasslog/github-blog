#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define ERR_EXIT(m) \
    do{ \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)

void do_service(int conn) {
    char recvbuf[1024];

    while(1) {
        memset(recvbuf, 0, sizeof(recvbuf));
        int ret = read(conn, recvbuf, sizeof(recvbuf));
        if(ret == 0) {
            printf("client close\n");
            break;
        } else if(ret == -1) {
            ERR_EXIT("read");
        }
        fputs(recvbuf, stdout);
        write(conn, recvbuf, sizeof(recvbuf));
    }
}

int main()
{
    int listenfd;
    if((listenfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        ERR_EXIT("socket");
    }

    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(8888);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int on = 1;
    if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) {
        ERR_EXIT("setsockopt");
    }

    if(bind(listenfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        ERR_EXIT("bind");
    }

    if(listen(listenfd, SOMAXCONN) < 0) {
        ERR_EXIT("listen");
    }

    struct sockaddr_in peeraddr;
    socklen_t peerlen = sizeof(peeraddr);
    int conn;
    pid_t pid;

    while(1) {
        if((conn = accept(listenfd, (struct sockaddr*)&peeraddr, &peerlen)) < 0) {
            ERR_EXIT("accept");
        }
        printf("ip=%s, port=%d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));

        if((pid = fork() < 0)) {
            close(listenfd);
            do_service(conn);
            close(conn);
            exit(EXIT_SUCCESS);
        } else {
            close(conn);
        }
    }

    close(listenfd);

    return 0;
}

