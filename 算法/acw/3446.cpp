#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    vector<int>j;
    vector<int>o;
    for(int i=0;i<10;i++)
    {
        int x;
        cin>>x;
        if(x%2==0) o.push_back(x);
        else j.push_back(x);
    }
    sort(o.begin(),o.end());
    sort(j.begin(),j.end(),[](const int& a,const int& b){return a>b;});
    for(int i=0;i<j.size();i++)
    {
        cout<<j[i]<<" ";
    }
    for(int i=0;i<o.size();i++)
    {
        cout<<o[i]<<" ";
    }
    
}