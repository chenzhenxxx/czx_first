#include<iostream>
using namespace std;
int dp[100][100];
int main()
{
   	int w[5] = { 0 , 2 , 3 , 4 , 5 };
	int v[5] = { 0 , 3 , 4 , 5 , 6 };
    int bagV=8;
    for(int i=0;i<5;i++)
    for(int j=1;j<=bagV;j++)
     if(j<w[i])
     dp[i][j]=dp[i-1][j];
     else
     {
         dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
     }
     cout<<dp[4][8];
}