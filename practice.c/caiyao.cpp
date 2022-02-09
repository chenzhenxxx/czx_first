#include<bits/stdc++.h>

using namespace std;
int tim[101];
int v[101];
int i,j;
int dp[101][1001];
      
int main()
{
      int t,m;
      cin>>t>>m;
      
      for(i=1;i<=m;i++)
      cin>>tim[i]>>v[i];

      for(i=1;i<=m;i++)
      for(j=t;j>=1;j--)
      {
          if(j>=tim[i])
          dp[i][j]=max(dp[i-1][j],dp[i-1][j-tim[i]]+v[i]);
          else
          dp[i][j]=dp[i-1][j];
      }
      cout<<dp[m][t];
}