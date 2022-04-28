#include<bits/stdc++.h>
using namespace std;
struct lu
{
    int x;
    int y;
    int t;
}l[100010];
int f[100010],m;
int find(int x)
{
    if(x!=f[x])
    f[x]=find(f[x]);
    return f[x];
}
void merge(int a,int b)
{
    int c=find(a);
    int d=find(b);
    if(c!=d)
    f[d]=c;
}
int check()
{   int sum=0;
    for(int i=1;i<=m;i++)
     {
         if(f[i]==i)
         sum++;
         if(sum==2)
         return 0;
     }
     return 1;
}
bool cmp(struct lu a,struct lu b)
{
    return a.t<b.t;
}
int main()
{
    int n;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
     {
         cin>>l[i].x>>l[i].y>>l[i].t;

     }
     sort(l+1,l+m+1,cmp);
     for(int i=1;i<=n;i++)
     f[i]=i;
     for(int i=1;i<=m;i++)
      {
          merge(l[i].x,l[i].y);
          if(check())
          {
              printf("%d",l[i].t);
              return 0;
          }
      }
      printf("-1");
      return 0;
}