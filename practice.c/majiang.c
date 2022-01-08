#include <stdio.h>
main()
{
    long long n,sum=0;
    scanf("%d",&n);
    long long a[n+1];
    long long b[n+1];                                          
    for(int i=1;i<=n;i++)
   {

    scanf("%lld",&b[i]);
    a[i]=1;
   }
    for(int i=2;i<=n;i++)
    { 
        if(b[i]>b[i-1])
        a[i]=a[i-1]+1;
        
    }
    for(int i=n;i>=2;i--)
    {    if(b[i]>b [i-1])
         continue;
         else
         {
        if(a[i-1]<=a[i])
        a[i-1]=a[i]+1;
         }
    }
    for(int i=1;i<=n;i++)
    sum+=a[i];
    printf("%lld",sum);
}