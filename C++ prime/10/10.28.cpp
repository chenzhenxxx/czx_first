#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9};
    vector<int> v1(a,a+9);
    vector<int>v2;
    vector<int>v3;
    list<int>l;
    copy(v1.begin(),v1.end(),inserter(v2,v2.begin()));
    copy(v1.begin(),v1.end(),back_inserter(v3));
    copy(v1.begin(),v1.end(),front_inserter(l));
     cout<<"inserter"<<endl;
    for(auto it=v2.begin();it!=v2.end();it++)
     cout<<*it<<" ";
     cout<<endl;
     cout<<endl;
     cout<<"back_inserter"<<endl;
    for(auto it=v3.begin();it!=v3.end();it++)
     cout<<*it<<" ";
     cout<<endl;
     cout<<"front_inserter"<<endl;
    for(auto it=l.begin();it!=l.end();it++)
     cout<<*it<<" ";
     cout<<endl;

}