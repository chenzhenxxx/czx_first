#include <stdio.h>
int a[401][401];
int book[401][401];
int total,bx,by;
void dfs(int x,int y)
{  int next[2][2]={{0,1},{1,0}};
int tx,ty;
    if(x==bx&&y==by)
    {
        total++;
        return;
    }
    for(int i=0;i<2;i++)
    {  tx=x+next[i][0];
       ty=y+next[i][1];
       
    if(tx<1||tx>bx||ty>by||ty<1)
    continue;
    book[tx][ty]=1;
    dfs(tx,ty);
    book[tx][ty]=0;
    return;
    }
    return;

}
main()
{
    int bx,by,mx,my;
    scanf("%d %d %d %d",&bx,&by,&mx,&my);
    a[bx-2][by-1]=1;
    a[bx-1][by-2]=1;
    a[bx+1][by-2]=1;
    a[bx+2][by-1]=1;
    a[bx-2][by+1]=1;
    a[bx-1][by+2]=1;
    a[bx+1][by+2]=1;
    a[bx+2][by+1]=1;

    dfs(0,0);
    printf("%d",total);
}


    