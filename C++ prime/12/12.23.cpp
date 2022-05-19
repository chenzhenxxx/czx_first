#include<bits/stdc++.h>
using namespace std;
int main()
{   char *c1="abc";
    char *c2="def";
    char *p=new char[strlen(c1)+strlen(c2)+1];
    strcat(p,c1);
    strcat(p,c2);
    cout<<p;
    delete [] p;
    string s1,s2;
    cin>>s1>>s2;
    unique_ptr<string []> u(new string [2]);
    u[0]=s1+s2;
    cout<<u[0];
    return 0;
}