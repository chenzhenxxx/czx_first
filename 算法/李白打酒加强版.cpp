#include <bits/stdc++.h>
using namespace std;
const int N=110,M=1000000007;
int dp[N][N][N];

int main(){
    int n,m;
    cin>>n>>m;
    dp[0][0][2]=1;

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=m;k++)
            {
                if(i&&k%2==0)
                {
                    dp[i][j][k]=dp[i-1][j][k/2]%M;
                }
                if(j)
                {
                    dp[i][j][k]=(dp[i][j][k]%M+dp[i][j-1][k+1]%M)%M;
                }
            }
        }
    }
    cout<<dp[n][m-1][1]<<endl;

}

