#include <stdio.h>
#include <math.h>
int jiecheng(int n)
{
    int i=1,jc=1;
    for(i=1;i<=n;i++)
     {
         jc*=i;
     }
     return jc;
}
int main ()
{
   int  n,jcsum=0;
   scanf("%d",&n);
   for(int i=1;i<=n;i++)
   {
       jcsum+=jc(i);
   }
   printf("%d",jcsum);
}