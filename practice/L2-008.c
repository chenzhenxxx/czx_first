#include<stdio.h>
#include<string.h>
int main()
{
    char a[1001];
    gets(a);
    int len=strlen(a);
    int i,j,l=0;
    for(i=0;i<len;i++)
     {
         for(j=0;i-j>=0&&i+j<len;j++)
          {
              if(a[i-j]!=a[i+j])
               break;
               if(2*j+1>l)
          {
              l=2*j+1;
          }

          }
          
          for(j=0;i-j>=0&&i+j<len;j++)
          {
              if(a[i-j]!=a[i+j+1])
               break;
               if(2*j>l)
          {
              l=2*j+1;
          }
               
          }
          
     }
     printf("%d\n",l);

}