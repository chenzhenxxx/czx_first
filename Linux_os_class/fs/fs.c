#include <fcntl.h>
#include <unistd.h>

int main() {
    int fileDescriptor;
    char buffer[1024];
    ssize_t bytesRead, bytesWritten;

    // 打开文件
    fileDescriptor = open("/home/chenzhenxxx/git/czx_first/Linux_os_class/fs/example.txt", O_RDONLY);
    if (fileDescriptor == -1) {
        // 处理文件打开失败的情况
        return -1;
    }

    // 读取文件内容
    bytesRead = read(fileDescriptor, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        // 处理读取文件失败的情况
        close(fileDescriptor); // 关闭文件
        return -1;
    }

    // 在控制台输出读取到的内容
    write(STDOUT_FILENO, buffer, bytesRead);

    // 写入文件内容
    bytesWritten = write(fileDescriptor, "Hello, World!", 13);
    if (bytesWritten == -1) {
        // 处理写入文件失败的情况
        close(fileDescriptor); // 关闭文件
        return -1;
    }

    // 关闭文件
    close(fileDescriptor);

    return 0;
}