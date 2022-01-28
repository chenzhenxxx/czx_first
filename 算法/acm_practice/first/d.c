#include <stdio.h>
int book[1005][1005];
main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    for( i=0;i<m;i++)
    {
        int x1,x2,y1,y2;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for( j=x1;j<=x2;j++)
       {
             book[j][y1]++;
             book[j][y2+1]--;
       }
         
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            book[i][j]+=book[i][j-1];
        printf("%d ",book[i][j]);
        }
        printf("\n");
    }

}