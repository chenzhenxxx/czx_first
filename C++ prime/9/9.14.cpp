#include<iostream>
#include<vector>
#include<list>
using namespace std;
int main()
{
    list<char*>old{"love","peace"};
    vector<string> names;
    names.assign(old.begin(),old.end());
    cout<<names[0]<<names[1];
}