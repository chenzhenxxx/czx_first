#include<bits/stdc++.h>
#define LL long long
#define PB push_back
 
using namespace std;
 
const int N=1e6+10,mod=1e9+7;
int n,m;
int a[N];
LL s[N];
int main()
{
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            if(1ll*i*i<=j)a[j]=i;
        }
    }
    for(int i=1;i<N;i++){
        s[i]=s[i-1]+(a[i]+i/a[i])/2;
        s[i]%=mod;
    }
    int t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        printf("%lld\n",s[n]);
    }
    return 0;
}