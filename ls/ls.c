#include<stdio.h>
#include <linux/limits.h> //包含PATH_MAX =260
#include<string.h>
#include<sys/stat.h> //提供 stat函数
#include<sys/types.h>
#include<stdlib.h>
#include<pwd.h>  //找uid
#include<grp.h>  //找gid
#include<time.h>  //转换时间
#define PARAM_NONE 0   //通过二进制 | 来标记flag
#define PARAM_a 1
#define PARAM_l 2
#define PARAM_R 4
#define PARAM_t 8
#define PARAM_r 16
#define PARAM_i 32
#define PARAM_s 64
int h=0,h_max=2;   //一行最多输出个数
void my_error(const char * err_string,int line)
{
    fprintf(stderr,"line:%d ",line);
    perror(err_string);
    exit(1);
}

void ls_a(struct stat buf,char *name,int color)
{
       char colorname[PATH_MAX+1];
       struct passwd *uid;
       struct group *gid;
       char mtime[100];
          //文档类别
         if(S_ISLNK(buf.st_mode))
          printf("l");
          else if(S_ISREG(buf.st_mode))
          printf("-");
          else if(S_ISDIR(buf.st_mode))
          printf("d");
          else if(S_ISCHR(buf.st_mode))
          printf("c");
          else if(S_ISBLK(buf.st_mode))
          printf("b");
          else if(S_ISFIFO(buf.st_mode))
          printf("f");
          else if(S_ISSOCK(buf.st_mode))
          printf("s");

          //user 权限
          if(buf.st_mode&S_IRUSR)
          printf("r");
          else if(buf.st_mode&S_IWUSR)
          printf("w");
          else if(buf.st_mode&S_IXUSR)
          printf("x");
          else
          printf("-");

          //group 权限
          if(buf.st_mode&S_IRGRP)
          printf("r");
          else if(buf.st_mode&S_IWGRP)
          printf("w");
          else if(buf.st_mode&S_IXGRP)
          printf("x");
          else
          printf("-");

          //other 权限
          if(buf.st_mode&S_IROTH)
          printf("r");
          else if(buf.st_mode&S_IWOTH)
          printf("w");
          else if(buf.st_mode&S_IXOTH)
          printf("x");
          else
          printf("-");
          printf("  ");

          //链接数
          printf("%4d",buf.st_nlink);
          //uid和gid
          uid=getpwuid(buf.st_uid);
          gid=getgrgid(buf.st_uid);
          if(uid==NULL||gid==NULL)
           {
               my_error("can't get id", __LINE__); // __LINE__正在编译的行号
           }
          printf("%-8s",uid->pw_name);
          printf("%-8s",gid->gr_name);
           
           //文档容量大小
          printf("%8d  ",buf.st_size);
          //最后修改时间
          strcpy(mtime,ctime(&buf.st_mtime));
          mtime[strlen(mtime)-1]='\0';  //不然会换行
          printf("%s",mtime);
          sprintf(colorname,"\033[%dm%s\033[0m",color,name);
          printf(" %-s\n",colorname);



}

void ls_i(struct stat buf,int color)
{      int h=0,h_max=2;

       h++;
       printf("%7d ",buf.st_ino);
       printf("")
}
#include <stdio.h>
#include <time.h>
 
int main ()
{
   time_t curtime;
 
   time(&curtime);
 
   printf("当前时间 = %s", ctime(&curtime));
 
   return(0);
}
int main(int argc,char*argv[])
{
   
   char path[PATH_MAX+1];   //写入路径
   int flag;  //判断参数。
   struct stat buf;
   int cnt=0,num=0;
   char param[100];
   flag=PARAM_NONE;
   for(int i=1;i<argc;i++)
    {
        if(argv[i][0]=='-')
         {
             for(int j=1;j<strlen(argv[i]);j++)
              {
                  param[cnt++]=argv[i][j];
              }
            num++;
         } 
    }

     //通过flag标记参数
      for(int k=0;k<cnt;k++)
       {
          if(param[k]=='a')
            flag|=PARAM_a;
             else if(param[k]=='l')
            flag|=PARAM_l;
             else if(param[k]=='i')
            flag|=PARAM_i;
             else if(param[k]=='R')
            flag|=PARAM_R;
             else if(param[k]=='r')
            flag|=PARAM_r;
             else if(param[k]=='t')
            flag|=PARAM_t;
             else if(param[k]=='s')
            flag|=PARAM_s;
          
        }

         if(num+1==argc)  //说明命令中没有路径，所以默认路径为./当前目录下
       {
          strcpy(path,'./');
          path[2]='\0';
           display_dir(flag,path);
          return 0;
       }
       
       for(int m=1;m<argc;m++)
         {    
              if(argv[m][0]=='-')
               {
                   
                   continue;
               }
              
              else
               {  if(stat(path,&buf)==-1)
                    {
                        my_error("stat",__LINE__);
                    }
                   if(S_ISDIR(buf.st_mode))  //是不是目录
                    {   if(path[strlen(argv[m])-1]!='/')
                         {
                           path[strlen(argv[m])]='/';
                           path[strlen(argv[m])+1]='\0';
                         }
                         else
                         {
                             path[strlen(argv[m])]='\0';
                         }
                        strcpy(path,argv[m]);
                        display_dir(flag,path);
                    }

                   else  //是文件
                    {   
                        strcpy(path,argv[m]);
                        display_file(flag,path);

                    } 
               }
         }
         return 0;


}
