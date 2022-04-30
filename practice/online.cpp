#include<bits/stdc++.h>
using namespace std;
inline const string & 
shorterString (const string &s1,const string &s2)
{
    return s1.size()<=s2.size()?s1:s2;
}
int main()
{  string s1,s2;
   cin>>s1;
   cin>>s2;
   cout<<shorterString(s1,s2)<<endl;
}