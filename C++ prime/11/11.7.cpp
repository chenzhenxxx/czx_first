#include<bits/stdc++.h>
using namespace std;
int main()
{   
    string xing;
    string name;
    map<string,vector<string>> family;
      cout<<"please input xing"<<endl;
    while(cin>>xing&&xing!="end")
    {   cout<<"please input people"<<endl;
        while(cin>>name&&name!="end")
          {
             family[xing].push_back(name);
          }
         cout<<"please input xing"<<endl;
    }
    for(auto it=family.begin();it!=family.end();it++)
    {
        cout<<it->first<<":"<<endl;
        auto it1=it->second.begin();
        for(;it1!=it->second.end();it1++)
         {
             cout<<*it1<<" ";
         }
    }

}