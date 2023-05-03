#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{   string s;
    while(cin>>s)
    { long long ans=0;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++)
    {
       ans+=(s[i]-'0')*(pow(2,i+1)-1);
    }
    cout<<ans<<endl;
    }
}