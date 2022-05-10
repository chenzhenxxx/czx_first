#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    int a,b,c,d;
    a=v.at(0);
    b=v[0];
    c=v.front();
    d=*v.begin();//begin返回的是第一个元素的迭代器要解引用
    cout<<a<<" "<<b<<" "<<c<<" "<<" "<<d;
}