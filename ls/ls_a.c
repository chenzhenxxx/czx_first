#include<stdio.h>
#include <linux/limits.h> //包含PATH_MAX =260
#include<string.h>
#define PARAM_NONE 0   //通过二进制 | 来标记flag
#define PARAM_a 1
#define PARAM_l 2
#define PARAM_R 4
#define PARAM_t 8
#define PARAM_r 16
#define PARAM_i 32
#define PARAM_s 64

int main(int argc,char*argv[])
{
   
   char path[PATH_MAX+1];   //写入路径
   int flag;  //判断参数。
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
      if(num+1==argc)  //说明命令中没有路径，所以默认路径为./当前目录下
       {
               

       }


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



}
