#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
    list<int> li{1,3,5,7,9};
    list<int>::iterator b=li.begin();
    list<int>::iterator e=li.end();
    vector<double> vec(b,e);

    for(int i=0;i<vec.size();i++)
     cout<<vec[i]<<ends;
     
       cout<<endl;

      vector<int> v(5,2);
    vector<int>::iterator begin=v.begin();
    vector<int>::iterator end=v.end();
    vector<double> ve(begin,end);

    for(int i=0;i<ve.size();i++)
     cout<<ve[i]<<ends;
}