#include<bits/stdc++.h>
using namespace std;
int main()
{   string s;
    const char *cp="Stately, plump Buck";
    s.assign(cp,7);
    cout<<s<<endl;
    s.insert(s.size(),cp+7);
    cout<<s;
}