#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> s[1000];
int depth[1000];
int root=0;
int ans=0;
void dfs(int p,int bf)
{    depth[p]=bf;
     if(depth[p]>ans)
     {
         ans=depth[p];
     }

    for(int i=0;i<s[p].size();i++)
     {
         dfs(s[p][i],bf+1);
     }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
     {
         int x;
         cin>>x;
         s[x].push_back(i);
         if(x==-1)
          {
              root=i;
          }

     }
     depth[root]=1;
     dfs(root,1);
     printf("%d\n",ans);
     int flag=0;
     for(int i=1;i<=n;i++)
      {
         if(depth[i]==ans)
          {
              if(flag==0)
               {
                   flag=1;
                   printf("%d",i);
               }
               else
               printf(" %d",i);
          }
      }
}