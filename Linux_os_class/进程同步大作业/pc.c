#include <semaphore.h>
#include<stdio.h>

#define N 10 // 缓冲区大小
#define M 8 // 线程数量

sem_t space, prod, buf;

int Buffer[N]; // 缓冲区数组
int in = 0; // 生产者往缓冲区中添加数据的下标
int out = 0; // 消费者从缓冲区中取出数据的下标

void *producer(void *p)
{
    for (int i = 0; i < 10; i++) {
        sem_wait(&space); // 如果缓冲区已满，则阻塞等待可用空间
        sem_wait(&buf); // 加锁，保证对缓冲区的操作互斥

        printf("Put a product into Buffer%d\n", in);
        Buffer[in] = 1; // 往缓冲区添加数据
        in = (in + 1) % N; // 更新下标，循环利用缓冲区

        sem_post(&prod); // 发出“可以消费”的信号，增加计数器
        sem_post(&buf); // 解锁缓冲区
    }
    return NULL;
}

void *consumer(void *p)
{
    for (int i = 0; i < 10; i++) {
        sem_wait(&prod); // 如果没有可消费的产品，则阻塞等待
        sem_wait(&buf); // 加锁，保证对缓冲区的操作互斥

        printf("Gets a product in Buffer%d\n", out);
        Buffer[out] = 0; // 从缓冲区取出数据
        out = (out + 1) % N; // 更新下标，循环利用缓冲区

        sem_post(&space); // 发出“可以生产”的信号，增加计数器
        sem_post(&buf); // 解锁缓冲区
    }
    return NULL;
}

int main()
{
    sem_init(&space, 0, N); // 初始化空闲空间的信号量
    sem_init(&prod, 0, 0); // 初始化“可消费产品数量”的信号量
    sem_init(&buf, 0, 1); // 初始化缓冲区的互斥锁

    pthread_t tid1[M], tid2[M]; // 定义生产者和消费者线程的数组

    for (int i = 0; i < M; i++) {
        pthread_create(&tid1[i], NULL, producer, NULL); // 创建生产者线程
    }

    for (int i = 0; i < M; i++) {
        pthread_create(&tid2[i], NULL, consumer, NULL); // 创建消费者线程
    }

    sem_destroy(&space); // 销毁信号量
    sem_destroy(&prod);
    sem_destroy(&buf);

    for (int i = 0; i < M; i++) {
         pthread_join(tid1[i], NULL); // 等待生产者线程执行完毕
    }

    for (int i = 0; i < M; i++) {
         pthread_join(tid2[i], NULL); // 等待消费者线程执行完毕
    }

    return 0; // 结束程序
}
