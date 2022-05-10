//list <deque<int>> a;
#include<iostream>
#include<vector>
using namespace std;
vector<int>v;
vector<int>::iterator Find(vector<int>::iterator begin, vector<int>::iterator end,int a)
{
    for(begin;begin!=end;begin++)
     {
         if(*begin==a)
         {
           return begin;
         }
     }
     return end;
}
int main()
{
    
    for(int i=0;i<10;i++)
    v.push_back(i);
    vector<int>::iterator begin=v.begin();
     vector<int>::iterator end=v.end();
     vector<int>::iterator tmp;
    if((tmp=Find(begin,end,11))!=end)
    {
        cout<<"find it!"<<"this is"<<*tmp;

    }
    else
    {
        cout<<"not";
    }
}