#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> s[10010];
int dedao[10010];
double sum=0;
int n;
double z,r;
void dfs(int id,double gl)
{
    if(dedao[id])
    {
        sum+=gl*dedao[id];
    }
    else
    {
        for(int i=0;i<s[id].size();i++)
         {
             dfs(s[id][i],gl*r);
         }
    }
}
int main()
{
   scanf("%d %lf %lf",&n,&z,&r);
   r=(100-r)*1.0/100;
   for(int i=0;i<n;i++)
    {
      int m;
      cin>>m;
      if(m==0)
       {
           double bet;
           cin>>bet;
           dedao[i]=bet;

       }
       else
       {
           for(int j=0;j<m;j++)
            {
                int x;
                cin>>x;
                s[i].push_back(x);
            }
       }
    }
    dfs(0,z);
    printf("%d",(int)sum);
}