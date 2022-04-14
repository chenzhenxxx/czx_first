#include<iostream>
using namespace std;
int a[100000];
int ans=0;
int main()
{
    int n;
    cin>>n;
    while(n--)
     {
         int b;
         cin>>b;
         if(b>a[ans])
          {ans++;
          a[ans]=b;
          }
          else 
          {
             int l=1,r=ans,res;
			while(l<=r){
				int mid=l+r>>1;
				if(a[mid]>=b) res=mid,r=mid-1;
				else l=mid+1;
			}
			a[res]=b;
          }
     }
     printf("%d",ans);
}
