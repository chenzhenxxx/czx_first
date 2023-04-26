#include <stdio.h>

// 进程结构体
typedef struct process {
    char name;          // 进程名字（用大写字母 A、B、C...表示）
    int burst_time;     // 执行时间
    int remaining_time; // 剩余执行时间
} Process;

int main() {
    int num_processes, time_quantum, i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    // 获取进程数量和时间片大小
    printf("请输入进程数量和时间片大小：");
    scanf("%d%d", &num_processes, &time_quantum);

    // 创建进程数组，并获取每个进程的执行时间
    Process processes[num_processes];
    for (i = 0; i < num_processes; i++) {
        printf("请输入进程%c的执行时间：", (char)(i + 65));  // 使用大写字母表示进程：A、B、C...
        scanf("%d", &processes[i].burst_time);
        processes[i].name = (char)(i + 65);
        processes[i].remaining_time = processes[i].burst_time;
    }

    // 时间片轮转算法
    int current_time = 0, completed_processes = 0;
    while (completed_processes < num_processes) {
        for (i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0) {   // 进程未执行完成
                if (processes[i].remaining_time > time_quantum) {  // 还有剩余时间，需要继续执行
                    printf("进程%c从时间%d到%d执行\n", processes[i].name,
                           current_time, current_time + time_quantum);
                    current_time += time_quantum;  // 更新当前时间
                    processes[i].remaining_time -= time_quantum;  // 减去已执行的时间
                } else {
                    printf("进程%c从时间%d到%d执行\n", processes[i].name,
                           current_time, current_time + processes[i].remaining_time);
                    // 计算等待时间和周转时间
                    int waiting_time = current_time - processes[i].burst_time;
                    int turnaround_time = current_time;
                    avg_waiting_time += waiting_time;  // 累加等待时间
                    avg_turnaround_time += turnaround_time;  // 累加周转时间
                    current_time += processes[i].remaining_time;  // 更新当前时间
                    processes[i].remaining_time = 0;  // 进程执行完成
                    completed_processes++;  // 完成的进程数加一
                }
            }
        }
    }

    // 打印平均等待时间和平均周转时间
    printf("平均等待时间 = %f\n", avg_waiting_time / num_processes);
    printf("平均周转时间 = %f\n", avg_turnaround_time / num_processes);

    return 0;
}
