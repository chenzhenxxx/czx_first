#include<bits/stdc++.h>
using namespace std;
vector<int>s[100000];
double dedao[50000];
void dfs(int id,double gl)
{
    
}
int main()
{
    int n,r;
    float z;
    cin>>n>>r>>z;
    for(int i=0;i<n;i++)
     {
         int m;
         cin>>m;
         if(m==0)
          { double y;
            cin>>y;
            dedao[i]=y;
          }
      else{
         for(int j=0;j<m;j++)
          {   int y;
              cin>>y;
              s[i].push_back(y);
          }
           }


     }
     dfs(0,z);
}