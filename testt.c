#include "myls2.h"


int main(const char argc, const char** argv)
{
    char path[PATH_MAX+1] = {};

    if(argc == 2 && !(strcmp(argv[1],"-R"))) // 判断命令格式
        strcpy(path,".");
    else if(argc != 3)
    {
        printf("格式有误！ \n");
        exit(EXIT_FAILURE);
    }
    else
        strcpy(path,argv[2]);

    if(!(strcmp(argv[1],"-R")))
    {
        struct stat file_message = {};
        int ret_stat = lstat(path, &file_message);

        if(ret_stat == -1)
               error_printf("stat");

        if(S_ISDIR(file_message.st_mode)) // 判断是否为目录
            list_dir(path);
        else
        printf("It is not dir!");
    }
    else
    {
        printf("error in main!\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}