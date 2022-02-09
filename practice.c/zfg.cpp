#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int m,n,i,j;
    cin>>m>>n;
    int ans[1001][1001];
    for(i=1;i<=m;i++)
    ans[i][1]=1;
    for(j=1;j<=n;j++)
    ans[1][j]=1;
    for(i=2;i<=m;i++)
    for(j=2;j<=n;j++)
    {
        ans[i][j]=(ans[i-1][j]+ans[i][j-1])%1000000007;
    }
    cout<<ans[m][n];
}