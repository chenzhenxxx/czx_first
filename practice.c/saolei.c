#include <stdio.h>
main()
{
    char b[102][102];
    int a[102][102];
    int n,m;
    scanf("%d %d\n",&n,&m);
    int i,j;
for(i=0;i<=n+1;i++)
for(j=0;j<=m+1;j++)
 a[i][j]=0;


    for(i=1;i<=n;i++)
    {
    for(j=1;j<=m;j++)
    {
        scanf("%c",&b[i][j]);
        if(b[i][j]=='*')
        a[i][j]=1;
    }
    getchar();
    }

    for(i=1;i<=n;i++)
    {
    for(j=1;j<=m;j++)
    {
        if(b[i][j]=='*')
        printf("*");
        else
        printf("%d",a[i][j+1]+a[i][j-1]+a[i-1][j-1]+a[i-1][j+1]+a[i+1][j-1]+a[i+1][j+1]+a[i-1][j]+a[i+1][j]);

    }
    printf("\n");
    }

}