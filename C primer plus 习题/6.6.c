   int ping(int n)
   {
       int s;
       s=n*n;
       return s;
   }
   int li(int n)
   {
       int s;
       s=n*n*n;
       return s;
   }
#include <stdio.h>
main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    printf("the number     2     3\n");
    for(i=n;i<=m;i++)
    {
        printf("%11d%5d%5d\n",i,ping(i),li(i));
    }
}