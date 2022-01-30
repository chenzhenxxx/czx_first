#include <stdio.h>
long long a[401][401];
int book[401][401];
int total,bx,by,mx,my;
main()
{
     int i,j;
    scanf("%d %d %d %d",&bx,&by,&mx,&my);
    mx++,my++,bx++,by++;
    book[mx-2][my-1]=1;
    book[mx-1][my-2]=1;
    book[mx+1][my-2]=1;
    book[mx+2][my-1]=1;
    book[mx-2][my+1]=1;
    book[mx-1][my+2]=1;
    book[mx+1][my+2]=1;
    book[mx+2][my+1]=1;
    book[mx][my]=1;
    a[1][1]=1;
    
		
    for(i=1;i<=bx;i++)
    for(j=1;j<=by;j++)
     if(book[i][j]!=1)
      {
                if(i==1&&j==1)
                continue;
                else
				a[i][j] += a[i - 1][j]+a[i][j - 1];
      }
    printf("%lld\n",a[bx][by]);
}