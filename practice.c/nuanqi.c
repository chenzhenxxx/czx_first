#include <stdio.h>
main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,count=0;
    int a[n+1];
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    
    for(i=2;i<=n;i++)
    {
        if(a[i]<a[i-1]+3)
        count+=a[i-1]+3-a[i];
    }
    printf("%d",n*m-count);
   
}