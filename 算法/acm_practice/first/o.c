#include <stdio.h>
main()
{
    int a[200];
    int t,n,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        scanf("%d",&a[j]);
        
          int sum=0;
        for(int k=1;k<=n;k++)
         { 
             if(a[k]-sum>k)
             sum+=(a[k]-k-sum);

         }
         printf("%d\n",sum);
         memset(a,0,200);
    }
}