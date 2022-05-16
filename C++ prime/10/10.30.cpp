#include<bits/stdc++.h>
using namespace std;
int main()
{
    
istream_iterator<int> in(cin),end;
vector<int> v;
ostream_iterator<int> out(cout," ");
    copy(in,end,back_inserter(v));
    sort(v.begin(),v.end());
        for_each(v.begin(),v.end(),[&out](int a){out=a;});

//  out=*in;


}