#include<iostream>
#include<memory>
#include<vector>
using namespace std;
vector<int> * make()
{
    return new vector<int>;
}
vector<int> * read(vector<int> *p)
{   int q;
    while(cin>>q)
    {
        p->push_back(q);
    }
    return p;
}
void print(vector<int> *p)
{
    for(auto it=p->begin();it!=p->end();it++)
    {
        cout<<*it<<" ";
    }
    delete p;
    p=nullptr;
}
int main()
{
   print(read(make()));
}