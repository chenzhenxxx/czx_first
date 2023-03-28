#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // 子进程
        printf("子进程正在执行...\n");
        sleep(2);
        printf("子进程执行完毕。\n");
        exit(0);
    } else {
        // 父进程
        printf("父进程正在执行...\n");
        sleep(5);
        printf("父进程执行完毕。\n");
    }
    return 0;
}