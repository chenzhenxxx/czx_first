#include <stdio.h>
int a[5010];
main()
{
    int n,i;
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i/2;j++)
    {
        a[i]+=a[j];
    }
        a[i]++;
    }
    printf("%d",a[n]);
}