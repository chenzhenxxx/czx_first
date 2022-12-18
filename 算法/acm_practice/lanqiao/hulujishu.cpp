#include<bits/stdc++.h>
using namespace std;
long long dp[1<<22][22];
int g[22][22];
inline int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int n=1<<21;
     for(int i=1;i<=21;i++)
      for(int j=1;j<=21;j++)
       {
         if(gcd(i,j)==1)
          {
            g[i-1][j-1]=g[j-1][i-1]=1;
          }
       }
    dp[1][0]=1;
    for(int i=1;i<n;i++)
     for(int j=0;j<21;j++){
        if(!(i>>j)&1)
        continue;

      for(int k=0;k<21;k++)
      {
        if((i>>k)&1 || !g[j][k])
        continue;
        
        dp[i+(1<<k)][k]+=dp[i][j];
      }
     }
     long long res=0;
     for(int i=0;i<21;i++)
       res+=dp[(1<<21)-1][i];
    cout<<res;
    return 0;
      
}
