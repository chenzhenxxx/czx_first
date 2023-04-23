#include<stdio.h>   //printf
#include<stdlib.h>  //exit
#include<string.h>  //strcpy
#include<sys/types.h> //pid_t
#include<unistd.h>  //read,write,fork,系统调用的头文件
#include <sys/wait.h>
//管道写
void write_to_pipe(int fd)
{
    char *message= "hello pipe!\n";
    write(fd,message,strlen(message)+1);
}

//管道读
void read_to_pipe(int fd)
{   
    char message[100];
    read(fd,message,100);
    printf("i read from pipe: %s",message);
}
int main()
{
    int fd[2]; //管道文件描述符
    pid_t pid; //进程Pid
    int stat_val; //返回值
    if(pipe(fd))  //创建管道
    {
      printf("creat pipe error!\n");
      exit(1);
    }

    pid= fork();  //创建进程 
    switch(pid)
    {
        case -1:
        printf("fork error!\n ");
        exit(1);
        case 0:
        close(fd[1]);
        read_to_pipe(fd[0]);
        exit(0);
        default:
        close(fd[0]);
        write_to_pipe(fd[1]);
        wait(&stat_val);

    }

}
