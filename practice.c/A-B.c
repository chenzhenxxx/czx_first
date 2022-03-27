#include<stdio.h>
#include<string.h>
main()
{   int flag=0,i,j;
    char a[10001];
    char b[10001];
    char ch;
  gets(a);
  gets(b);
    for( i=0;i<strlen(a);i++)
    {
             flag=0;
    for( j=0;j<strlen(b);j++)
      {
             if(a[i]==b[j])
             {
                 flag=1;
                 break;
             }
      }
      if(flag==0)
      printf("%c",a[i]);
    }
}