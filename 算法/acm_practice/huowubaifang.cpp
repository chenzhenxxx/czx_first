#include<bits/stdc++.h>
using namespace std;
const long long N=2021041820210418;
long long int a[5000];
int ans=0;
long long sum=0;
void func()
{
  for(long long int i=1;i*i<=N;i++)
  {   if(N%i==0)
      {
      a[ans++]=i;
      if(i*i!=N)
      a[ans++]=N/i;
      }
  }
}
int main()
{
   func();
   for(int i=0;i<ans;i++)
   {
    for(int j=0;j<ans;j++)
    {
      for(int k=0;k<ans;k++)
      {
        if(a[i]*a[j]*a[k]==N){
          sum++;
        }
      }
    }
   }
   cout<<sum<<endl;
}