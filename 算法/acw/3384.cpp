#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string str;
int k;
void dfs()
{
    char c=str[k++];
    if(c=='#') return ;
    dfs();
     cout<<c<<" ";
    dfs();
}
int main()
{
    cin>>str;
    dfs();
}