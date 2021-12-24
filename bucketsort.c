#include <stdio.h>
int max(int*a,int n)
{
    int i,x=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>x)
        x=a[i];
    }
    return x;
}
main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    int m=(max(a,n)+1);
    int b[m];
    for(i=0;i<m;i++)
    b[i]=0;
    for(i=0;i<n;i++)
    {
        b[a[i]]++;
    }

    for(i=0;i<m;i++)
    {
        while(b[i])
        {
            printf("%d ",i);
            b[i]--;

        }
    }
    
    
}