#include<iostream>
using namespace std;
int ans=0,m,n;
int a[50000];
int book[50000];
void dfs(int money,int index)
{
      if(money>m||index>n-1)
    {
        return;
    }
    
    if(money==m)
    {
        ans++;
        return;
    }
   

    for(int i=index;i<n;i++)
    {
        if(!book[i])
        {
              book[i]=1;
             dfs(money+a[i],i);
             book[i]=0;
        }
    }
    return;

}
int main()
{
   
    cin>>n>>m;
    int i;
    for(i=0;i<n;i++)
    cin>>a[i];
    dfs(0,0);
    cout<<ans;
}