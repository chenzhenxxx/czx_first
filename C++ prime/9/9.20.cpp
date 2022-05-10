#include<iostream>
#include<list>
#include<deque>
using namespace std;
int main()
{
    list<int> l;
    for(int i=0;i<10;i++)
     l.push_back(i);

    deque<int> os;
    deque<int>js;

    list<int>::iterator it=l.begin();
    for(it;it!=l.end();it++)
    {
        if(*it&1)//奇数
        {
            js.push_back(*it);
        }
        else
        {
            os.push_back(*it);
        }
             
    }
    cout<<"jishu"<<endl;
    for(auto it=js.begin();it!=js.end();it++)
     cout<<*it<<" ";

     cout<<"oushu"<<endl;
    for(auto it=os.begin();it!=os.end();it++)
     cout<<*it<<" ";
}