#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
#include<list>
using namespace std;
int main()
{
    int a[10]={0,2,4,4,3,2,4,5,6,10};
    vector<int> v(a,a+10);
    int val=4;
    cout<<"num:"<<count(v.cbegin(),v.cend(),val)<<endl;
    
    string s[10]={"abcdd","czx","CZX","czx","666"};
    list<string> l(s,s+10);
    string va="666";
    cout<<"num2:"<<count(l.cbegin(),l.cend(),va);                                       
    



}