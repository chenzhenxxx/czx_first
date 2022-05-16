#include<bits/stdc++.h>
using namespace std;
int main()
{
    multimap<string,string>m;
    pair<string,string> p;
    string author;
    cout<<"please input author and book"<<endl;
    while(cin>>p.first>>p.second&&p.first!="end")
    {
        m.insert(p);
    }
    string s;
    cout<<"which author you want to erase"<<endl;
    while(cin>>s&&s!="end")
    {
        auto pos=m.equal_range(s);
        m.erase(pos.first,pos.second);
    }
    for(auto it=m.begin();it!=m.end();it++)
     {
         cout<<it->first<<":"<<endl;
         for(auto it2=it->second.begin();it2!=it->second.end();it2++)
         
             cout<<(*it2)<<endl;
         
     }

}