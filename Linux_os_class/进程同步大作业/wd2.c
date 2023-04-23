
#include <semaphore.h>
#include <stdio.h>
#include<pthread.h>

#define M 10 // 定义宏M为10，代表读写的线程数量
#define N 20 // 定义宏N为20，表示每个writer进行写操作前需要先获取的sread信号量计数

// 创建两个信号量: sdata 和 sread
sem_t sdata; // sdata用来控制writer线程的访问
sem_t sread; // sread用来控制readcount的并发访问

// 定义reader线程函数
void* reader(void* p) {
    sem_wait(&sdata); // 获取sdata信号量
    sem_wait(&sread); // 获取sread信号量

    sem_post(&sdata); // 释放sdata信号量
    printf("%lu are reading\n", pthread_self()); // 输出当前有几个线程正在读取共享资源
    sem_post(&sread); // 释放sread信号量

    return NULL;
}

// 定义writer线程函数
void *writer(void *p)
{
    sem_wait(&sdata); // 获取对sdata的访问权限
    for(int i=0;i<N;i++)
    {
        sem_wait(&sread); // 获取sread信号量
    }

    printf("%lu are writing\n",pthread_self()); // 输出正在进行写入操作

    for(int i=0;i<N;i++)
    {
        sem_post(&sread); // 释放sread信号量
    }

    sem_post(&sdata); // 释放对sdata的访问权限

    return NULL;
}

int main(void)
{
    sem_init(&sdata, 0, 1); // 初始化sdata信号量，初值1
    sem_init(&sread, 0, N); // 初始化srcount信号量，初值N

    pthread_t tid1[M], tid2[M]; // 创建writer线程和reader线程数组

    for (int i = 0; i < M; i++) {
        pthread_create(&tid1[i], NULL, writer, NULL); // 创建生产者线程
    }

    for (int i = 0; i < M; i++) {
        pthread_create(&tid2[i], NULL, reader, NULL); // 创建消费者线程
    }

    sem_destroy(&sdata); // 销毁sdata信号量
    sem_destroy(&sread); // 销毁sread信号量

    return 0;
}
