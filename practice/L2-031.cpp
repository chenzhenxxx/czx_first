#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> s[115000];
int silu[115000];
int men[115000];
int max_len=0;
int door=1;
void dfs(int id,int step)
{
    if(silu[id]==1)
     {
         if(step>max_len)
          {   
              max_len=step;
              door=id;
          }
         return;
     }
     for(int i=0;i<s[id].size();i++)
     {
         dfs(s[id][i],step+1);
     }
}
int main()
{
     int n,start=1;
     cin>>n;
     for(int i=1;i<=n;i++)
      {
          int x;
          cin>>x;
          if(x==0)
          {
              silu[i]=1;
              
          }
          else
          {
              for(int j=1;j<=x;j++)
               {   int m;
                   cin>>m;
                   men[m]++;
                   s[i].push_back(m);
               }
          }
      }
           
           for(int i=1;i<=n;i++)
            if(men[i]==0)
             start=i;

          dfs(start,0);
    
      printf("%d",door);
}