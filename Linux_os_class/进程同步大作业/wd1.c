#include <semaphore.h>
#include <stdio.h>
#define M 10 // 定义宏M为10，代表读写的线程数量

sem_t sdata, srcount; // 创建两个信号量，sdata用来控制writer线程的访问，srcount用来控制readcount的并发访问
int readcount = 0; // 设置全局变量readcount表示同时在读取共享资源的线程数

// 定义reader线程函数
void *reader(void *p)
{
    sem_wait(&srcount); // 等待对srcount的访问权限
    readcount = readcount + 1; // 记录现在有几个线程同时读取共享资源
    if (readcount == 1) // 如果这是第一个开始访问共享资源的线程
    {
        sem_wait(&sdata); // 等待sdata的访问权限
    }
    sem_post(&srcount); // 释放对srcount的访问权限，其他线程可以继续修改readcount的值

    printf("%d are reading\n", readcount); // 输出当前有几个线程正在读取共享资源

    sem_wait(&srcount); // 再次等待对srcount的访问权限
    readcount = readcount - 1; // 修改readcount的值，表示当前有几个线程正在读取共享资源
    if (readcount == 0) // 如果已经没有正在读取共享资源的线程了
    {
        sem_post(&sdata); // 释放对sdata的访问权限，其他线程可以开始写入共享资源了
    }
    sem_post(&srcount); // 释放对srcount的访问权限

    return NULL;
}

// 定义writer线程函数
void *writer(void *p)
{
    sem_wait(&sdata); // 等待对sdata的访问权限
    printf("writing\n"); // 输出正在进行写入操作
    sem_post(&sdata); // 释放对sdata的访问权限

    return NULL;
}

int main(void)
{
    sem_init(&sdata, 0, 1); // 初始化sdata信号量
    sem_init(&srcount, 0, 1); // 初始化srcount信号量

    pthread_t tid1[M], tid2[M]; // 创建线程数组
    for (int i = 0; i < M; i++) {
        pthread_create(&tid1[i], NULL, writer, NULL); // 创建生产者线程
    }

    for (int i = 0; i < M; i++) {
        pthread_create(&tid2[i], NULL, reader, NULL); // 创建消费者线程
    }

    sem_destroy(&sdata); // 销毁信号量
    sem_destroy(&srcount);


    return 0;
}
