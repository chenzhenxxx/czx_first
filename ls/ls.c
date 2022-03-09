#include<stdio.h>
#include <linux/limits.h> //包含PATH_MAX =260
#include<string.h>
#include<sys/stat.h> //提供 stat函数
#include<sys/types.h>
#include<stdlib.h>
#include<pwd.h>  //找uid
#include<grp.h>  //找gid
#include<time.h>  //转换时间
#include<unistd.h>
#include<dirent.h>
#define PARAM_NONE 0   //通过二进制 | 来标记flag
#define PARAM_a 1
#define PARAM_l 2
#define PARAM_R 4
#define PARAM_t 8
#define PARAM_r 16
#define PARAM_i 32
#define PARAM_s 64
int h=0,h_max=2;
int g_maxlen;   //一行最多输出个数
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

void ls_i(int color,char *name)
{   struct stat buf;
    if(stat(name,&buf)==-1)
    {
        my_error("stat",__LINE__);
    }
    int h_max=2,j=0,len=strlen(name);
       char colorname[NAME_MAX+1];
       h++;
       printf("%7d ",buf.st_ino);
       sprintf(colorname,"\033[%dm%s\033]m",color,name);
       printf("%-s",colorname);

       for(int i=0;i<len;i++)
       {
           if(name[i]<0)
                j++;   
       }
       len=g_maxlen-len+j/3;
        for(int i=0;i<len+5;i++)
		printf(" ");
	if( h == h_max)
	{
		printf("\n");
		h = 0;
	}
}


void ls_s(int color,char * name)
{   char colorname[NAME_MAX+1];
    struct stat buf;
    int len=strlen(name);
    if(stat(name,&buf)==-1)
     {
         my_error("stat",__LINE__);
     }
     sprintf(colorname,"/033[%dm%s\033[0m",color,name);
     printf("%4d",buf.st_blocks);
     printf("  %s",colorname);
     h++;
       len=g_maxlen-len;
     for(int i=0;i<len+4;i++)
      {
          printf(" ");
      }
     if(h==h_max)
     {
         printf("\n");
         h=0;
     }
}

void time_quicksort(long filetime[],char **filename,int begin,int end)
{  char tmpname[PATH_MAX+1];
   if(begin>end)
   return ;
    int i=begin;
    int j=end;
    long t;
    long tmp=filetime[begin];
    while(i!=j)
    {
      while(filetime[j]<=tmp&&j>i)
      j--;
      while(filetime[i]>=tmp&&j>i)
      i++;
      if(j>i)
      { //换时间
        t=filetime[i];
        filetime[i]=filetime[j];
        filetime[j]=t;
        //换文件名
        strcpy(tmpname,filename[i]);
        strcpy(filename[i],filename[j]);
        strcpy(filename[j],tmpname);

      }


    }
    filetime[begin]=filetime[i];
    filetime[i]=tmp;
     strcpy(tmpname,filename[i]);
     strcpy(filename[i],filename[begin]);
     strcpy(filename[begin],tmpname);

    time_quicksort(filetime,filename,0,i-1);
     time_quicksort(filetime,filename,i+1,end);
}

//ls -t //不用单独实现   

void display_dir(int flag,char*path)
{
    DIR *dir;
    struct dirent * ptr;
    int cnt=0;  //计算文件个数
    char filename[256][PATH_MAX+1];
    long filetime[256];
    dir=opendir(path);
    if(dir==NULL)
    {
        my_error("openpath",__LINE__);
    }
    while(ptr=readdir(dir)!=NULL)
     {
         int hanzi=0;
         int nohanzi=0;
         for(int i=0;i<strlen(ptr->d_name[i]);i++)
          {    
              if(ptr->d_name[i]<0)
              hanzi++;
              else
              nohanzi++;
          }
        int len=hanzi/3+nohanzi;
        if(g_maxlen<len)
        g_maxlen=len;

        cnt++;
     }
     closedir(dir);

     if(cnt>256)  //过多文件
      printf("%d :too many files under this dir",__LINE__);
      
      
      
      dir=opendir(path);
     for(int i=0;i<cnt;i++)
     {
         if(ptr=readdir(dir)==NULL)
          {
              my_error("readdir",__LINE__);
          }

         strncpy(filename[i],path,strlen(path));
         filename[i][strlen(path)]='\0';
         strcat(filename,ptr->d_name);
         filename[i][strlen(path)+strlen(ptr->d_name)]='\0';
         closedir(dir);

     }
      
       if(flag&PARAM_t)
        {
             flag-=PARAM_t;
             struct stat buf;
             for(int i=0;i<cnt;i++)
              {
                  if(stat(filename[i],&buf)==-1)
                   {
                       my_error("stat",__LINE__);
                   }
                   filetime[i]=buf.st_mtime;
              }
             time_quicksort(filetime,filename,0,cnt);
            
        }
        else
        





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
