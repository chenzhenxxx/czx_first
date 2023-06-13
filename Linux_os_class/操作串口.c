#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<termios.h>

int main()
{
    int fd;
    struct termios tty;
    char buf[255];

    // 打开串口
    fd = open("/dev/tty", O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    // 配置参数
    tcgetattr(fd, &tty);
    cfsetospeed(&tty, B9600);
    cfsetispeed(&tty, B9600);   
    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~CSIZE;   
    tty.c_cflag |= CS8;     
    tty.c_cflag &= ~PARENB; 
    tty.c_cflag &= ~CSTOPB; 
    tty.c_cflag &= ~CRTSCTS;
    tty.c_cc[VTIME]=0;
    tty.c_cc[VMIN]=1;

    // 应用新配置
    tcsetattr(fd, TCSANOW, &tty);

    // 发送数据
    write(fd, "Hello, world!", 13); 

    // 等待接收数据
    while (read(fd, buf, 1) <= 0);
    printf("Received: %s\n", buf);

    close(fd);
    return 0;
}
