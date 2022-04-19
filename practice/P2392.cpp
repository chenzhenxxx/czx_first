#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a[5],sum=0,time[1000],dp[1000],t=0;
   for(int i=1;i<=4;i++)
    cin>>a[i];
    for(int i=1;i<=4;i++)
     {
       sum=0;
       for(int j=1;j<=a[i];j++)
        {
          cin>>time[j];
          sum+=time[j];
        }
        for(int j=1;j<=a[i];j++)
         for(int k=sum/2;k>=time[j];k--)
         {
           dp[k]=max(dp[k],dp[k-time[j]]+time[j]);
         }
         t+=sum-dp[sum/2];
         for(int j=1;j<=sum/2;j++)
          dp[j]=0;
     }
     printf("%d",t);
}