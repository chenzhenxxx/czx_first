#include<bits/stdc++.h>
using namespace std;
map<int,int> up,down;
set<int> s;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {  int ans=0,final=0;
       up.clear();down.clear();s.clear();
       int n;
       cin>>n;
       while(n--)
        {
            int a,b;
            cin>>a>>b;
            s.insert(a);
            s.insert(b);
            up[a]++;
            down[b]++;
        }
        for(auto it=s.begin();it!=s.end();it++)
         {
             final+=up[*it];
             final-=down[*it];
             ans=max(ans,final);

         }
         cout<<s.size()<<" "<<ans;
    }
}