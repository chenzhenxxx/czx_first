#include <stdio.h>
int total, n,m, zdx, zdy, book[50][50], a[50][50];
void dfs(int x, int y)
{
    int tx, ty, i;
    int z[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    if (x == zdx && y == zdy)
    {
        total++;
        return;
    }
    for (i = 0; i <= 3; i++)
    {
        tx =x+z[i][0];
        ty =y+ z[i][1];
        if (tx < 1 || tx > zdx || ty < 1 || ty > zdy)
            continue;
        if (a[tx][ty] == 0 && book[tx][ty] == 0)
        {
            book[tx][ty] = 1;
            dfs(tx, ty);
            book[tx][ty] = 0;
        }
    }
    return;
}
main()
{
    int k, ge,x,y;
    scanf("%d %d %d", &n, &m, &ge);
    scanf("%d %d %d %d", &x, &y, &zdx, &zdy);
    int zx, zy;
    for (k = 1; k <= ge; k++)
    {
        scanf("%d %d", &zx, &zy);
        a[zx][zy] = 1;
    }
    a[x][y]=1;
    dfs(x,y);
    printf("%d",total);
   
}