#include<iostream>
#include<memory>
#include<vector>
using namespace std;
shared_ptr<vector<int>> make()
{   return make_shared<vector<int>>();
    //shared_ptr<vector<int>> _ptr(new vector<int>);
    //return _ptr;
}
shared_ptr<vector<int>> read(shared_ptr<vector<int>> p)
{   int q;
    while(cin>>q)
    {
        p->push_back(q);
    }
    return p;
}
void print(shared_ptr<vector<int>> p)
{
    for(auto it=p->begin();it!=p->end();it++)
    {
        cout<<*it<<" ";
    }
    //delete p;
    //p=nullptr;
}
int main()
{
   print(read(make()));
}