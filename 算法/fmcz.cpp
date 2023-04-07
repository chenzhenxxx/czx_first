#include<iostream>
#include<cmath>
using namespace std;
int dp[110][100010];
int a[110];
int n;
int sum=0;
int ans=0;
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    sum+=a[i];
  }
  for(int i=0;i<=n;i++)
  {
    dp[i][0]=1;
  }
  
  for(int i=1;i<=n;i++)
  {
    for(int j=0;j<=sum;j++)
    {
      dp[i][j] = dp[i-1][j]||dp[i-1][j+a[i]]||dp[i-1][abs(j-a[i])];
    }
  }
  for(int i=1;i<=sum;i++)
  {
    if(dp[n][i]==1)
    {
      ans++;
    }
  }
  cout<<ans<<endl;
  return ans;
}