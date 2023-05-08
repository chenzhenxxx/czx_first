#include <algorithm>
#include <iostream>
using namespace std;
const int N=1e5 +10;
int q[N];

int SL(int l,int r,int x)
{
    while(l<r)
    {
        int mid=l+r>>1;
        if(q[mid]>=x) r=mid;
        else l=mid+1;
    }
    return l;
}

int SR(int l,int r,int x)
{
    while(l<r)
    {
       int mid=l+r+1>>1;
       if(q[mid]<=x) l=mid;
       else r=mid-1;
    }
    return r;
}
int main()
{ 
   int n,m;
   scanf("%d %d",&n,&m);
   for(int i=0;i<n;i++)
   {
    scanf("%d",&q[i]);
   }
   while(m--)
   {
     int x;
     cin>>x;
     int l=SL(0,n-1,x);
     if(q[l]==x)
     {
        cout<<l<<" ";
        int r=SR(0,n-1,x);
        cout<<r<<endl;
     }
     else cout<<-1<<" "<<-1<<endl;
   }
}