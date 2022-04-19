#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> s[11500];
int js[11500];
int form[11500];
int st[11500];
int eend=0,start=0;
int max_len=0;
int dep[11500];
void dfs(int id,int step)
{
    if(s[id].size()==0)
     {
         if(dep[id]==max_len)
          {
             eend=id;
             
          }
          return;
     }
     for(int i=0;i<s[id].size();i++)
      {
            dep[s[id][i]]=step+1;
            max_len=max(step+1,max_len);
            form[s[id][i]]=id;
            dfs(s[id][i],step+1);

      }
}
void print(int x)
{
    if(x!=start)
    print(form[x]);
     if(x!=eend)
    cout<<" "<<x;
    else 
    cout<<x;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
     {   int x;
         cin>>x;
         for(int j=0;j<x;j++)
          {
              int m;
              cin>>m;
              st[m]++;
              s[i].push_back(m);
          }
          sort(s[i].begin(),s[i].end());
          reverse(s[i].begin(),s[i].end());

     }
     for(int i=0;i<n;i++)
      {
          if(st[i]==0)
           {   start=i;
               break;
           }
      }
    for(int i=0;i<n;i++)
        form[i]=i;
      dfs(start,1);
      printf("%d\n",max_len);
      print(eend);

      
}

