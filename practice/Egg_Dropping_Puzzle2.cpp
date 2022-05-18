#include<iostream>
#include<algorithm>
using namespace std;
int dp[500][500];
int main()
{
   int egg,folor;
   cin>>egg>>folor;
   for(int i=0;i<=egg;i++)
    for(int j=0;j<=folor;j++)
    dp[i][j]=j;
   for(int i=0;i<=egg;i++)
   { dp[i][1]=1;
    dp[i][0]=0;
   }
   for(int j=0;j<=folor;j++)
    {
        dp[0][j]=0;
        dp[1][j]=j;
    }

    for(int i=2;i<=egg;i++)
     for(int j=2;j<=folor;j++)
      {
          for(int k=1;k<=j;k++)
           {
               dp[i][j]=min(dp[i][j],max(dp[i-1][k-1],dp[i][j-k])+1);
           }
      }
      cout<<dp[egg][folor];


}