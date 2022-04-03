#include<stdio.h>
int f[1010];
void init()
{
    int i;
    for(i=1;i<1010;i++)
     {
         f[i]=i;
     }
}
int find(int a)
{
    if(a==f[a])
    return a;
    else
    return f[a]=find(f[a]);
}
void merge(int a,int b)
{
    int c=find(a);
    int d=find(b);
    if(c!=d)
    f[c]=d;

}
int main()
{
    int n,m;
    while(1)
    {   int ans=0;
        scanf("%d %d",&n,&m);
        init();
        for(int j=1;j<=m;j++)
         {
             int a,b;
             scanf("%d %d",&a,&b);
             merge(a,b);
         }
         for(int x=1;x<n;x++)
           
              if(find(x)!=find(x+1))
               {
                  f[find(x)]=find(x+1);
                  ans++;
               }
          
          printf("%d\n",ans);
    }
}