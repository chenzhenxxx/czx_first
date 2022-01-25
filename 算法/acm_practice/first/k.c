#include <stdio.h>
int s[55];
main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=4;i++)
    s[i]=i;
    for(i=5;i<=n;i++)
     {
         s[i]=s[i-1]+s[i-3];
     }
     printf("%d",s[n]);

}