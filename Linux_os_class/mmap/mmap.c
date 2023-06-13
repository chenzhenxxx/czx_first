#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/time.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<errno.h> // 添加头文件以使用 errno 变量
 
#define MAX 10000
 
int main()
{
    int i = 0;
    int count = 0, fd = 0;
    struct timeval tv1, tv2;
    int *array = (int *)malloc(sizeof(int)*MAX);
 
    /*read*/
 
    gettimeofday(&tv1, NULL);
    fd = open("/home/chenzhenxxx/git/czx_first/Linux_os_class/mmap/test.txt", O_RDWR);
    if(fd == -1) { // 添加错误检查
        printf("Failed to open file: %s\n", strerror(errno));
        return -1;
    }
    if (sizeof(int)*MAX != read(fd, (void *)array, sizeof(int)*MAX))
    {
        printf("Reading data failed...\n");
        close(fd); // 添加关闭文件描述符
        return -1;
    }
    for (i = 0; i < MAX; ++i)
        ++array[i];
    lseek(fd, 0, SEEK_SET); // 将文件指针移回开头
    if (sizeof(int)*MAX != write(fd, (void*)array, sizeof(int)*MAX))
    {
        printf("Writing data failed...\n");
        close(fd); // 添加关闭文件描述符
        return -1;
    }
    free(array);
    close(fd);
    gettimeofday(&tv2, NULL);
    printf("Time of read/write: %dms\n", tv2.tv_usec - tv1.tv_usec);
 
    /*mmap*/
 
    gettimeofday(&tv1, NULL);
    fd = open("/home/chenzhenxxx/git/czx_first/Linux_os_class/mmap/test.txt", O_RDWR);
    if (fd == -1) { // 添加错误检查
        printf("Failed to open file: %s\n", strerror(errno));
        return -1;
    }
    array = mmap(NULL, sizeof(int)*MAX, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (array == MAP_FAILED) { // 添加错误检查
        printf("Failed to map memory: %s\n", strerror(errno));
        close(fd);
        return -1;
    }
    for (i = 0; i < MAX; ++i)
        ++array[i];
    munmap(array, sizeof(int)*MAX);
    msync(array, sizeof(int)*MAX, MS_SYNC);
    close(fd); // 添加关闭文件描述符
    gettimeofday(&tv2, NULL);
    printf("Time of mmap: %dms\n", tv2.tv_usec - tv1.tv_usec);
 
    return 0;
}
