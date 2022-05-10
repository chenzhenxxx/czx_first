#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
    int ia[]={0,1,1,2,3,5,8,13,21,55,89};
    vector<int> v(ia,ia+11);
    list<int> l(ia,ia+11);
    auto it=v.begin();
    while(it!=v.end())
    {
        if(*it&1)
        it=v.erase(it);
        else 
        it++;
    }

    auto i=l.begin();
    while(i!=l.end())
    {
        if(!(*i&1))
        i=l.erase(i);
        else 
        i++;
    }
    cout<<"v:"<<endl;
    for(auto x=v.begin();x!=v.end();x++)
      cout<<*x;
      auto j=l.begin();
    while(j!=l.end())
    {
        if(!(*j&1))
        j=l.erase(i);
        else 
        j++;
    }
    cout<<"l:"<<endl;
    for(auto y=l.begin();y!=l.end();y++)
      {
          cout<<*y;
      }

}