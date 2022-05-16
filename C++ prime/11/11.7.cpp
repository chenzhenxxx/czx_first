#include<bits/stdc++.h>
using namespace std;
int main()
{   
    string xing;
    map<string,vector<string>> family;
    vector<pair<string,string>> birthday;
    pair<string,string> p;
      cout<<"please input xing"<<endl;
    while(cin>>xing&&xing!="end")
    {   cout<<"please input people and birthday"<<endl;
        while(cin>>p.first>>p.second&&p.first!="end")
          {  
             family[xing].push_back(p.first);
             birthday.push_back(p);

          }

         cout<<"please input xing"<<endl;
    }
    for(auto it=family.begin();it!=family.end();it++)
    {
        cout<<it->first<<":"<<endl;
       auto it1=birthday.begin();
        for(;it1!=birthday.end();it1++)
         {
             cout<<it1->first<<" "<<it1->second<<endl;
         }
         cout<<endl;
    }

}