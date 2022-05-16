#include<bits/stdc++.h>
#include<utility>
using namespace std;
int main()
{   pair<string,int>p;
    vector<pair<string,int>>v;
    string s;
    size_t num,cnt=0;
    while(cin>>p.first>>p.second&&p.first!="end")
    {
      v.push_back(p);
     cnt++;
    }
    for(auto it=v.begin();it!=v.end();it++)
    {
         cout<<it->first<<" "<<it->second<<endl;
    }
}