#include <stdio.h>
int n,m;
int e[1001];
void init()
{  for(int i=1;i<=n;i++)
   e[i]=i;
    
}

int getf(int x)
{
    if(e[x]==x)
    return e[x];
    else
    {
        e[x]=getf(e[x]);
        return e[x];
    }

}

void merge(int x,int y)
{
    if(getf(e[x])!=getf(e[y]))
    e[getf(e[y])]=getf(e[x]);
}
int main()
{
    int i,x,y;
    scanf("%d %d",&n,&m);
    init();
    for(i=1;i<=m;i++)
    {  
        scanf("%d %d",&x,&y);
        merge(x,y);
    }

    int sum=0;
    for(i=1;i<=n;i++)
    {
        if(e[i]==i)
        sum++;
    }
    printf("%d",sum);


}