#include<iostream>
#include<string>
#include<deque>
#include<list>
using namespace std;
int main()
{
    string s;
    list<string> d;
    while(cin>>s)
    {
         d.push_back(s);
    }
    list<string>::iterator it=d.begin();
    for(it;it!=d.end();it++)
     cout<<*it;
}