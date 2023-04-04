#include <string.h>  // 字符串操作头文件
#include <stdlib.h>  // 标准库头文件
#include <pthread.h>  // POSIX 线程库头文件
#include <unistd.h>  // 标准 UNIX 库头文件
#include <sys/syscall.h>  // 系统调用库头文件

#define gettid() syscall(__NR_gettid)  // 宏定义，获取当前线程 ID

pthread_t ntid;  // 全局变量，保存新线程 ID

// 线程执行函数，打印进程、线程和线程ID，然后暂停等待进程被杀死
void *printtids(void *s)
{
    pid_t pid;  // 进程 ID
    pid_t ktid;  // 内核级线程 ID
    pthread_t utid;  // 用户级线程 ID

    pid = getpid();  // 获取当前进程 ID
    ktid = gettid();  // 获取内核级线程 ID
    utid = pthread_self();  // 获取用户级线程 ID

    printf("%s pid %u ktid %u  utid %u (0x%x)\n", s, (unsigned int)pid, 
           (unsigned int)ktid, (unsigned int)utid, (unsigned int)utid);  // 打印信息

    pause();  // 暂停等待进程被杀死
}

// 主函数
int main()
{
    pthread_create(&ntid, NULL, printtids, "new thread:");  // 创建一个新线程，并执行 printtids 函数
    printtids("main thread:");  // 执行 printtids 函数，打印主线程信息
    sleep(1);  // 等待1秒钟，保证新线程能够被成功创建和执行

    return 0;  // 返回
}
