#include <stdio.h>
#include <stdbool.h>
#define MAX 10000005
int m[MAX];
int book[MAX];
int count;
bool huiwen(int x)
{ 
    int j[11];
    int len=0,i,flag=1;
    if(x==5||x==7)
    flag=1;
    else
    {
    while(x>0)
    {
        j[len++]=x%10;
        x=x/10;
    }
    if(len==1)
    flag=0;
    else
    {
    for(i=0;i<len/2;i++)
    {
        if(j[i]!=j[len-i-1])
        {
            flag=0;
            break;
        }
    }
    }
    }
     return flag;
}
void  xianxingshai(int b)
{
     int i;
     for(i=2;i<=b;i++)
     { 
         if(book[i]==0)
         {
           m[count++]=i;
         }
           for(int j=0;j<count&&i*m[j]<MAX;j++)
           {
               book[i*m[j]]=1;
               if(i%m[j]==0)
               break;
           }
        
     }
}
main()
{
    int a,b,i;
    scanf("%d %d",&a,&b);
    if(b>10000000)
    b=10000000;
     xianxingshai(b);
     for(i=0;i<count;i++)
     if(m[i]>a)
     break;
     i--;
    for(;i<count&&m[i]<=b;i++)
    {
        if(huiwen(m[i]))
        printf("%d\n",m[i]);
        
    }

}

