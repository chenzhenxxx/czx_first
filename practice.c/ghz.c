#include <stdio.h>
int a[401][401];
int book[401][401];
int total,bx,by,mx,my;
main()
{
    
    scanf("%d %d %d %d",&bx,&by,&mx,&my);
    a[mx-2][my-1]=1;
    a[mx-1][my-2]=1;
    a[mx+1][my-2]=1;
    a[mx+2][my-1]=1;
    a[mx-2][my+1]=1;
    a[mx-1][my+2]=1;
    a[mx+1][my+2]=1;
    a[mx+2][my+1]=1;
    a[mx][my]=1;
    for(int i=0;i<=bx;i++)
    book[i][0]=1;
    for(int j=0;j<=by;j++)
    book[0][j]=1;
    
    for(int i=1;i<=bx;i++)
    for(int j=1;j<=by;j++)
    {

     if(i==1&&j==1)
     continue;
    if(a[i][j]==0)
    book[i][j]=book[i-1][j]+book[i][j-1];
    }
    printf("%d",book[bx][by]);
}


    

    