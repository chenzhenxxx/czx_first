#include<stdio.h>
main()
{   
    int n,m,i;
    scanf("%d %d",&n,&m);
    int a[n+1];
    char name[n+1][15];
    for(i=1;i<=n;i++)
    {
        scanf("%d %s",&a[i],&name[i]);
    }
    int j=1;
    for(i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==a[j])
        {
            j=j-y;
            if(j<1)
            j+=n;
        }
        else
        {
            j=j+y;
        if(j>n)
            j=j%n;
        }

    }
    printf("%s",name[j]);


}