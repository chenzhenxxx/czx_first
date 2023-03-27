#include<stdio.h>
int f[15010];
int n,ans=0;
void init()
{
    for(int i=1;i<=2*n;i++)
    f[i]=i;
}
int find(int a)
{
    if(f[a]!=a)
    f[a]=find(f[a]);
    return f[a];
}
void merge(int a,int b)
{
    int c=find(a);
    int d=find(b);
    if(c!=d)
    f[d]=c;
}
int main()
{
    scanf("%d\n",&n);
    int m;
    scanf("%d\n",&m);
    init();
    while(m--)
    {
        char opt;
        int p,q;
        scanf("%c %d %d",&opt,&p,&q);
        while(getchar()!='\n');
        if(opt=='F')
        {
            merge(p,q);
        }
        else if(opt=='E')
        {
            merge(p,q+n);
            merge(q,p+n);
        }
    }

      for(int i=1;i<=n;i++)
      if(f[i]==i)
       {
           ans++;
       }
       printf("%d",ans);
}