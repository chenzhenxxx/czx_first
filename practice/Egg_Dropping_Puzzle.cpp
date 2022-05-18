#include<iostream>
#include<algorithm>
using namespace std;
int memo[500][500];
int drow(int egg ,int folor)
{   int ans=folor;
    if(egg==1)
    return folor;
    if(folor==0)
    return 0;
    if(memo[egg][folor])//剪枝，避免重复循环
		return memo[egg][folor];
    for(int i=1;i<=folor;i++)
     {
         ans=min(ans,max(drow(egg-1,i-1),drow(egg,folor-i))+1);
         memo[egg][folor] = ans;
     }
     return ans;


}
int main()
{
    int egg,folor;
    cin>>egg>>folor;
    cout<<drow(egg,folor)<<endl;
}