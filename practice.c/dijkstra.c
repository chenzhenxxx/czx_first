#include <stdio.h>

main()
{
    int n,m,j,k,i,u,v;
    scanf("%d %d",&n,&m);
    int e[n+1][m+1];
    int book[n+1];
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        if(i==j)
        e[i][j]=0;
        else
        e[i][j]=999999;
    }


    for(i=1;i<=m;i++)
    {
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        e[x][y]=w;
    }
    int dis[n+1];
     dis[1]=0;
     for(i=1;i<=n;i++)
     dis[i]=e[1][i];
     
     book[1]=1;
      int min;
     for(i=1;i<=n-1;i++)
     {
        
         min=999999;
         for(j=1;j<=n;j++)
         {     if(book[j]==0&&dis[j]<min)

             {
                min=dis[j];
                u=j;
             }
         }
         book[u]=1;
         for(v=1;v<=n;v++)
         {    if(e[u][v]<999999)
             {
                 if(dis[v]>dis[u]+e[u][v])
                 dis[v]=dis[u]+e[u][v];
             }
         }
     }

     for(i=1;i<=n;i++)
     printf("%d ",dis[i]);

}