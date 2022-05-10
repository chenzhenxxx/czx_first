#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
    vector<int> a(5,1);
    vector<int> b(5,1);
    vector<int> c(4,1);
    list<int> d(5,1);
    if(a==b)
    cout<<"y";
    else
    cout<<"n";
    cout<<endl;
    if(a==c)
    cout<<"y";
    else
    cout<<"n";
    cout<<endl;
   
}