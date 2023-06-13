#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <syslog.h>

int main() {
    pid_t pid, sid;

    // 创建子进程
    pid = fork();

    // 如果创建失败，则退出程序
    if (pid < 0) {
        exit(EXIT_FAILURE);
    }

    // 如果该子进程已经存在，那么退出程序。
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    // 修改文件模式掩码
    umask(0);

    // 开启新的会话，让子进程成为进程组长
    sid = setsid();
    if (sid < 0) {
        exit(EXIT_FAILURE);
    }

    // 将当前工作目录改为根目录
    if ((chdir("/")) < 0 ) {
        exit(EXIT_FAILURE);
    }

    // 关闭标准输入、输出、错误输出描述符
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    // 打开系统日志
    openlog("printer_daemon", LOG_PID, LOG_DAEMON);

    // 每隔一段时间执行一次任务
    while(1) {
        syslog(LOG_INFO, "Printer daemon is running...");
        /* 在这里添加具体的打印机守护任务 */
        sleep(60);
    }

    // 关闭系统日志
    closelog();

    // 程序正常退出
    exit(EXIT_SUCCESS);
}
