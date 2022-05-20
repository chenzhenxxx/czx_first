#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define per(i,a,b) for(int i=a;i>=(b);--i)
#define mem(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define pi pair<int, int>
#define mk make_pair
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll f[100],dp[100],dp1[100];
int main()
{
    ll ans=3;
    f[1]=1;
    dp1[1]=1;
    for(int i=2;i<=6;++i){
 
 
        dp1[i]=dp1[i-1];//大洞
        if(i-3>=1)dp1[i]+=dp[i-3];//第四天
        f[i]=f[i-1]+dp1[i];
        dp[i]=dp1[i-1];//小洞产生
        //printf("i:%d dp1:%lld dp:%lld f:%lld\n",i,dp1[i],dp[i],f[i]);
        ans+=3*f[i];
     }
 
    cout<<ans;
}