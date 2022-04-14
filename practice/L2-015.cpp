#include<iostream>
#include<algorithm>
using namespace std;
int cmp(double a,double b)
{
    return a>=b;
}
int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    int a[10010][20];
    double d[10010];
    for(int i=0;i<n;i++)
     {   int sum=0;
         for(int j=0;j<k;j++)
      {
          cin>>a[i][j];
          sum+=a[i][j];

      }
      d[i]=sum;
     }
     for(int i=0;i<n;i++)
      {   int x=a[i][0],y=a[i][0];
          for(int j=1;j<k;j++)
           {
              x=max(x,a[i][j]);
              y=min(y,a[i][j]);
           }
           d[i]=d[i]-x-y;
           d[i]=d[i]*1.0/(k-2);
      }
      sort(d,d+n,cmp);
      for(int i=m-1;i>=0;i--)
       {
           printf("%.3f ",d[i]);
       }
}