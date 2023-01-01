#include<iostream>
#include<vector>
using namespace std;
 vector<int> tree[100050];
int dfs(int k)
{  int ans=0;
  if(tree[k].size()==0)
  return 0;
  for(int i=0;i<tree[k].size();i++)
   {
    ans=max(ans,dfs(tree[k][i]));
   }
   return ans+tree[k].size();
}
int main()
{
  int n;
  cin>>n;
  for(int i=2;i<=n;i++)
   {int x;
    cin >>x;
    tree[x].push_back(i);
   }
   cout<<dfs(1)<<endl;
}