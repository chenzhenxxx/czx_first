#include<netinet/in.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<fcntl.h>
#include<ctype.h>
#define PORT 10000
#define MAXLINE 4096

int main(int argc,char **argv)
{
    int cfd,sfd,len=0;
    socklen_t addrlen;
    struct sockaddr_in6 serveraddr,clientaddr;
    char ptr[MAXLINE];
    char buf[MAXLINE];
    sfd=socket(AF_INET6,SOCK_STREAM,0);
    bzero(&serveraddr,sizeof(serveraddr));
    serveraddr.sin6_family=AF_INET6;
    serveraddr.sin6_port=htons(PORT);
    serveraddr.sin6_addr=in6addr_any;
    bind(sfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
    listen(sfd,10); //最大未决未决连接的数量
    while(1)
    {
        addrlen=sizeof(clientaddr);
        cfd=accept(sfd,(struct sockaddr *)&clientaddr,&addrlen);
        printf("clinet ip %s\tport %d\n",
        inet_ntop(AF_INET6,&clientaddr.sin6_addr,ptr,sizeof(ptr)),
        ntohs(clientaddr.sin6_port));
        len=read(cfd,buf,sizeof(buf));
        int i=0;
        while(i<len)
        {
            buf[i]=toupper(buf[i]);
            i++;
        }
        write(cfd,buf,len);
        close(cfd);

         


    }
    close(sfd);
    return 0;




}