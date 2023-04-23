#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

int main()
{
    int shmid;
    char *shmaddr;

    // 创建共享内存段
    shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget error");
        exit(1);
    }

    // 将共享内存映射到进程地址空间中
    shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (void *)-1) {
        perror("shmat error");
        exit(1);
    }

    // 在共享内存中写入数据
    sprintf(shmaddr, "Hello, shared memory!");

    // 从共享内存中读取数据并打印
    printf("Received from shared memory: %s\n", shmaddr);

    // 分离共享内存
    if (shmdt(shmaddr) == -1) {
        perror("shmdt error");
        exit(1);
    }

    // 删除共享内存段
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl error");
        exit(1);
    }

    return 0;
}