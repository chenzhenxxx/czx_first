#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// 进程入口函数
void child_process(void)
{

    printf("Hello from child process(pid=%d)\n", getpid());
    exit(0); // 子进程执行完毕，退出程序
}

// 线程入口函数
void *thread_func(void *arg)
{
    printf("Hello from child thread(tid=%ld)\n", pthread_self());
    return NULL; // 子线程执行完毕，退出线程
}

int main(int argc, char *argv[])
{
    pid_t pid;
    pthread_t tid;
    int ret;
    pid = fork(); // 创建进程
    if (pid == -1)
    { // fork()失败
        printf("Error: fork() failed.\n");
        return 1;
    }

    if (pid == 0)
    {                    // 子进程中
        child_process(); // 子进程执行child_process()函数
    }
    else
    { // 父进程中
        printf("Hello from parent process(pid=%d)\n", getpid());

        ret = pthread_create(&tid, NULL, thread_func, NULL); // 创建线程
        if (ret != 0)
        { // pthread_create()失败
            printf("Error: pthread_create() failed.\n");
            return 1;
        }

        pthread_join(tid, NULL); // 等待子线程结束

        printf("Child thread finished.\n");
    }

    return 0;
}