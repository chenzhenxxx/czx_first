#include<iostream>
using namespace std;

const int maxn=1010;
int f[maxn],dp[maxn];
int ans=1; 
int main()
{
	int N;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>f[i];
		dp[i]=1; 
	}

	
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(f[j]<f[i]) dp[i]=max(dp[i],dp[j]+1);
		}		
		ans=max(ans,dp[i]);
	}
	cout<<ans;		
} 
