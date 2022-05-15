#include<bits/stdc++.h>

using namespace std;
bool cmp(const string s)
{
    return s.size()>5;
}
int main()
{
    vector<string> s{"aaa","chenzhenxin","is","hamesome","boysss"};
        auto it=partition(s.begin(),s.end(),cmp);
        for(auto i=s.begin();i!=it;i++)
         {
            cout<<*i<<endl;
         }


    
}