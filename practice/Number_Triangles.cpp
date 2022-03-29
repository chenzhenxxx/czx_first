#include<iostream>
#include<algorithm>
using namespace std;
int a[1001][1001];
int dp[1001][1001];
int main()
{
  int r,i,j;
  cin>>r;
  for(i=1;i<=r;i++)
  for(j=1;j<=i;j++)
   cin>>a[i][j];
   
   for(j=1;j<=r;j++)
    dp[r][j]=a[r][j];
   for(i=r-1;i>=1;i--)
    for(j=1;j<=i;j++)
    {
        dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
    }
    cout<<dp[1][1];
}
