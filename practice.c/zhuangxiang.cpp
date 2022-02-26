#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int r,n,cnt=0;
    int a[20000];
    int dp[20000];
    cin>>r;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    for(int j=r;j>=a[i];j--)
     dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
    printf("%d",r-dp[r]);

}