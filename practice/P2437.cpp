#include<bits/stdc++.h>
using namespace std;
int f[1001][1001];
int len=1;
void big_plus(int x)
{
    for(int i=1;i<=len;i++)
    f[x][i]+=f[x-1][i]+f[x-2][i];
    for(int i=1;i<=len;i++)
    {
        if(f[x][i]>9)
        {   f[x][i+1]+=f[x][i]/10;
            f[x][i]%=10;
        }
    }
    if(f[x][len+1])
    len++;

}
int main()
{
    int n,m;
    cin>>n>>m;
    f[1][1]=1;
    f[2][1]=2;
    for(int i=3;i<=m-n;i++)
    big_plus(i);
    for(int i=len;i>=1;i--)
    cout<<f[m-n][i];

}