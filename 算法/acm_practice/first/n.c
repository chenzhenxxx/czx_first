#include <stdio.h>
main()
{
    int t,n;
    char b[100005];
    char a[100005];
    scanf("%d",&t);
    for(int i=0;i<t;i++)
     {
         scanf("%d %s",&n,&b);
         a[0]='1';
         for(int j=1;j<n;j++)
          {
              if(a[j-1]+b[j-1]-2*'0'!=b[j]+1-'0')
              a[j]='1';
              else
              a[j]='0';
          }
          puts(a);
     }
     
}