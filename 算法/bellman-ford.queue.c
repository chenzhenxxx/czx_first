#include <stdio.h>
int book[1000];
main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    int u[m+1],v[m+1],w[m+1],first[n+1],next[m+1];
    int que[101]={0},dis[n+1];
    int head=1,tail=1;
    for(i=1;i<=m;i++)
    scanf("%d %d %d",&u[i],&v[i],&w[i]);
    for(i=1;i<=n;i++)
    first[i]=-1;

    for(i=1;i<=m;i++)
    {
        next[i]=first[u[i]];
        first[u[i]]=i;
    }

    for(i=1;i<=n;i++)
    dis[i]=999999;
    dis[1]=0;
    que[1]=1;
    book[1]=1;
    tail++;
    while(head<tail)
    {  int k=first[que[head]];
       while(k!=-1)
       {
           if(dis[v[k]]>dis[u[k]]+w[k])
           {
               dis[v[k]]=dis[u[k]]+w[k];
           if(book[v[k]]==0)
           {
               que[tail]=v[k];
               tail++;
               book[v[k]]=1;
           }
           }
        
        k=next[k];
    }
        book[que[head]]=0;
        head++;


    }

    for(i=1;i<=n;i++)
    printf("%d ",dis[i]);


}