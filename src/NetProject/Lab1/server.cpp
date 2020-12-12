#include <sys/types.h>
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <fcntl.h>
#include <sys/shm.h>
#include "socketwrapper.h"
using namespace std;

#define MYPORT  8885
#define QUEUE   20
#define BUFFER_SIZE 1024


int main()
{
    // creat socket
    int server_sockfd = Socket(AF_INET,SOCK_STREAM, 0);

    ///定义sockaddr_in
    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(MYPORT);
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    ///bind，成功返回0，出错返回-1
    if(Bind(server_sockfd,(struct sockaddr *)&server_sockaddr,sizeof(server_sockaddr))==-1)
    {
        perror("bind");
        exit(1);
    }

    ///listen，成功返回0，出错返回-1
    if(Listen(server_sockfd,QUEUE) == -1)
    {
        perror("listen");
        exit(1);
    }

    ///客户端套接字
    char buffer[BUFFER_SIZE];
    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);

    ///成功返回非负描述字，出错返回-1
    int conn = Accept(server_sockfd, (struct sockaddr*)&client_addr, &length);
    if(conn<0)
    {
        perror("connect");
        exit(1);
    }

    char sendbuf[BUFFER_SIZE];
    while(1)
    {
        memset(buffer,0,sizeof(buffer));
        Recv(conn, buffer, sizeof(buffer),0);
        if(strcmp(buffer,"exit\n")==0)
            break;
        fputs(buffer, stdout);
        if (int len = fgets(sendbuf, sizeof(sendbuf), stdin) != NULL){
            Send(conn, sendbuf,100,0);
        }
        memset(sendbuf, 0, sizeof(sendbuf));
        memset(buffer, 0, sizeof(buffer));

    }
    Close(conn);
    Close(server_sockfd);
    return 0;
}