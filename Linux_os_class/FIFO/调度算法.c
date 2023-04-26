#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
int main()
{ //设置调度策略为FIFO
     struct sched_param param;
     param.sched_priority = 99;
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1)
    {
         perror("sched_setscheduler");
        exit(EXIT_FAILURE);
     } // 执行任务
     int i;
    for (i = 1; i <= 10; i++)
    {
        printf("Task %d is running\n", i);
        sleep(1);
    }
    return 0;
}