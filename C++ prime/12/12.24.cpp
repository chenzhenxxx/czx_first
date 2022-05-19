#include<bits/stdc++.h>
using namespace std;
int main()
{   string p;
    char *un(new char[5]);
    cin>>p;
    strcat(un,p.c_str());
    cout<<p;
    delete [] un;

}