
#include<netinet/in.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<fcntl.h>

#define PORT 10000
#define MAXLEN 4096
int main(int argc,char **argv)
{
    struct sockaddr_in6 serveraddr;
    int cfd;
    int len;
    char buf[MAXLEN];
    
     cfd=socket(AF_INET6,SOCK_STREAM,0); 
     bzero(&serveraddr,sizeof(serveraddr));
     serveraddr.sin6_family=AF_INET6;
     inet_pton(AF_INET6,"127.0.0.1",&serveraddr.sin6_addr);
     serveraddr.sin6_port=htons(PORT);

     connect(cfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr)); //将cfd的主动socket连接到由serveraddr指定的监听socket；
     while(1)
     {
     write(cfd,argv[1],strlen(argv[1]));
     len=read(cfd,buf,sizeof(buf));
     write(STDOUT_FILENO,buf,len);

     close(cfd);
     return 0;
     }

}