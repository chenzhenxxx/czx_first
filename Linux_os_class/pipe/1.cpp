#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int fd[2];  // 用于存储管道的读取和写入文件描述符
    pid_t pid;  // 存储子进程ID
    char buf[256];  // 用于存储管道传递的数据

    // 创建管道
    if (pipe(fd) < 0) {
        cerr << "Error: Failed to create pipe." << endl;
        return 1;
    }

    // 创建子进程
    pid = fork();
    if (pid < 0) {
        cerr << "Error: Failed to fork." << endl;
        return 1;
    } else if (pid == 0) {
        // 子进程
        close(fd[1]);  // 关闭写入端
        // 从管道中读取数据
        read(fd[0], buf, sizeof(buf));
        cout << "Received: " << buf << endl;
        close(fd[0]);  // 关闭读取端
        return 0;
    } else {
        // 父进程
        close(fd[0]);  // 关闭读取端
        string msg = "Hello, child! This is parent.";
        // 将数据写入管道
        write(fd[1], msg.c_str(), strlen(msg.c_str()) + 1);
        wait(NULL);  // 等待子进程结束
        close(fd[1]);  // 关闭写入端
        return 0;
    }
}