#include <stdio.h>

#define MAX 10000   // 声明数字个数

int main() {

    FILE *fp = fopen("/home/chenzhenxxx/git/czx_first/Linux_os_class/mmap/test.txt", "wb");   // 打开二进制文件，并写入数字
    
    if (fp == NULL) {
        printf("Failed to create file.\n");
        return -1;
    }

    for (int i = 0; i < MAX; ++i) {
        int num = i + 1;   // 写入数字
        fwrite(&num, sizeof(int), 1, fp);
    }
    
    fclose(fp);   // 关闭文件

    return 0;
}
