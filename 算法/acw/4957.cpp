#include<iostream>
#include<cstring>
using namespace std;
struct plane{
    int t,d,l;
};
int n;
struct plane pe[11];
bool fg[11];
bool dfs(int cnt,int last)
{
    if(cnt==n) return true;
    for(int i=0;i<n;i++)
    {   
        int t=pe[i].t,l=pe[i].l,d=pe[i].d;
        if(!fg[i]&&t+d>=last)
        {   fg[i]=1;
            if(dfs(cnt+1,max(last,t)+l)) return true;
            else return false;
            fg[i]=0;
            
        }
    }
}
int main()
{
    cin>>n;
    while(n--)
    {
       int m;
       cin>>m;
       for(int i=0;i<m;i++)
       {
        int t,d,l;
        cin>>t>>d>>l;
        pe[i]={t,d,l};
       }
       if(dfs(0,0))
       cout<<"Yes"<<endl;
       else
       cout<<"No"<<endl;
       memset(pe,0,sizeof(pe));
    }
}