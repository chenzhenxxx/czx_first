#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *run(void *arg)
{
    int policy;
    pthread_getschedparam(pthread_self(), &policy, arg);
    // 获取线程调度参数
    printf("Thread is running, priority = %d\n", ((struct sched_param *)arg)->sched_priority);
    sleep(1);
    printf("Thread is finished\n");
    pthread_exit(NULL);
}
int main()
{
    // 设置线程属性
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setschedpolicy(&attr, SCHED_FIFO);
    for (int i = 0; i < 4; i++)
    {
        // 设置调度参数
        struct sched_param param;
        param.sched_priority = i * 10 + 50;
        // 假设进程优先级范围为50~90
        pthread_attr_setschedparam(&attr, &param);
        // 创建线程并运行
        pthread_t tid;
        if (pthread_create(&tid, &attr, run, &param))
        {
            printf("Thread creation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    pthread_attr_destroy(&attr);
    return 0;
}
