#include<iostream>
#include<algorithm>
using namespace std;
struct xiangzi
{
    int t;
    int v;
    double a;
}x[100050];
bool cmp(struct xiangzi b,struct xiangzi c)
{
    return b.a>c.a;
}
int main()
{   int n,i,j,ans=0,sum=0;
    int  total=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
      cin>>x[i].t>>x[i].v;
      x[i].a=x[i].v*1.0/x[i].t;
      sum+=x[i].v;
    }
    sort(x,x+n,cmp);
    for(j=0;j<n;j++)
    {
      
      sum-=x[j].v;
      total+=2*sum*x[j].t;
    }
    cout<<total;
}