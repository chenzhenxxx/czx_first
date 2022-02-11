#include<iostream>
#include<algorithm>

using namespace std;
int a[50005];
int b[50005];
int n;
bool cmp(int c,int d)
{
    return c>d;
}

int main()
{
  int i,j;
  cin>>n;
  
   for(i=0;i<n;i++)
   {
    cin>>a[i];
    b[i]=a[i];
   }
  
     sort(a,a+n);
        for(i=1;i<n;i++)
     {
         a[i]=a[i]*a[i-1]+1;
         sort(a+i,a+n);
     }
     int max=a[n-1];
     
     sort(b,b+n,cmp);
     for(j=1;j<n;j++)
     {
         b[j]=b[j]*b[j-1]+1;
        
     }
      int min=b[n-1];
     cout<<max-min;
     
      
  
 
}