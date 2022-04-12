#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int dp[1000][1000];
int main()
{
    int n,m;
    memset(dp,0,sizeof(dp));
    int a[1000];
    int b[1000];
    scanf("%d",&n);
    m=n;
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(int j=1;j<=m;j++)
    scanf("%d",&b[j]);
    for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
       {   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                  if(a[i]==b[j])
                  dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);

       }
       printf("%d",dp[n][m]);

}