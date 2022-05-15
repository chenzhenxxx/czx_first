#include<iostream>
#include<vector>
using namespace std;
int main()
{
   vector<int> v(5,10);
   fill_n(v.begin(),v.size(),0);
    for(auto s=v.begin();s!=v.end();s++)
     cout<<*s<<endl;
   }