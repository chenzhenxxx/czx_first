#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int fifo(int n, int bt[])
{
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0; // 将第一个进程的等待时间设为0
    wt[0] = 0;                       // 计算每个进程的等待时间和周转时间
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    } // 输出结果
    printf("Process\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t %d\t\t %d\t\t %d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tat / n);
}
int main()
{ // 进程数量和每个进程需要的CPU时间
    int n = 4;
    int bt[] = {6, 3, 4, 5};
    int pid;
    for (int i = 0; i < n; i++)
    {
        pid = fork(); // 创建子进程
        if (pid < 0)
        {
            printf("Fork error!\n");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {                 // 子进程运行
            sleep(bt[i]); // 模拟进程执行的时间
            printf("Child process %d is finished\n", i + 1);
            exit(EXIT_SUCCESS);
        }
    } // 父进程等待所有子进程都结束
    for (int i = 0; i < n; i++)
    {
        wait(NULL);
    }
    fifo(n, bt); // 调用FIFO函数    
    return 0;
}