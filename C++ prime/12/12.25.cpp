#include<bits/stdc++.h>
using namespace std;
int main()
{   int n;
    cin>>n;
    allocator<string> alloc;
    string s;
    auto p=alloc.allocate(n);
    auto q=p;
    while(cin>>s&&q!=p+10)
     {
         alloc.construct(q++,s);
     }
     auto m=q-1;
     while(m!=(p-1))
     {
         cout<<*(m)<<endl;
         m--;
     }
     while(q!=p)
     {
         alloc.destroy(--q);
     }
     alloc.deallocate(p,10);
     return 0;


}