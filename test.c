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
void name_quicksort(char filename[256][PATH_MAX+1],int begin,int end)
{   if(begin>=end)
    return;
    int i=begin;
    int j=end;
    char tmpname[100];
    strcpy(tmpname,filename[begin]);
    tmpname[strlen(filename[begin])]='\0';
    while(i!=j)
    {
        while((i<j)&&(strcmp(filename[j],tmpname)>0))
        j--;
        while((i<j)&&(strcmp(filename[i],tmpname)<0))
        i++;
        if(i<j)
        {
            char tmp[100];
            strcpy(tmp,filename[i]);
            tmp[strlen(filename[strlen(filename[i])])]='\0';
            strcpy(filename[i],filename[j]);
            strcpy(filename[j],tmp);

        }

    }
         strcpy(tmpname,filename[i]);
         strcpy(filename[i],filename[begin]);
         strcpy(filename[begin],tmpname);
         name_quicksort(filename,begin,i-1);
         name_quicksort(filename,i+1,end);
         

}
int main()
{
    char a[100][20];
    for(int i=0;i<5;i++)
    {
        scanf("%s",a[i]);
    }

    name_quicksort(a,0,4);
     
     for(int i=0;i<5;i++)
    {
        printf("%s\n",a[i]);
    }
}