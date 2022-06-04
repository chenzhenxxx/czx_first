#include<stdio.h>
#include<unistd.h>
int main(int argc,char**argv)
{   char buf[100];
    int num=read(STDIN_FILENO,buf,100);
    printf("%d %d %s" ,argc,num,buf);
}