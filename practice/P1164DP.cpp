#include<iostream>
using namespace std;
int dp[500][50000];
int a[50000];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
    cin>>a[i];


    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
     {      if(j==a[i])
           dp[i][j]=dp[i-1][j]+1;

           if(j>a[i])
           dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i]];
      
           if(j<a[i])
           dp[i][j]=dp[i-1][j];
     }
     cout<<dp[n][m];     
}