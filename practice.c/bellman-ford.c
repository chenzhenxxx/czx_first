#include <stdio.h>
main()
{
    int n,m,i,j;
    scanf("%d %d",&n,&m);
    int v[m+1],u[m+1],w[m+1],dis[n+1];
    for(i=1;i<=m;i++)
    scanf("%d %d %d",&u[i],&v[i],&w[i]);

    for(i=1;i<=n;i++)
    dis[i]=9999999;
    dis[1]=0;
    for(i=1;i<=n-1;i++)
    { int check=0;
    for(j=1;j<=m;j++)
    {
        if(dis[v[j]]>dis[u[j]]+w[j])
        {
            dis[v[j]]=dis[u[j]]+w[j];
            check=1;
        }

    }
      if(check==0)
      break;
    }
    int flag=0;
    for(i=1;i<=m;i++)
    if(dis[v[i]]>dis[u[i]]+w[i])
    flag=1;
    if(flag)
    printf("有负权回路\n");
    else
    {
    for(i=1;i<=n;i++)
    for(i=1;i<=n;i++)
    printf("%d ",dis[i]);
    }

}