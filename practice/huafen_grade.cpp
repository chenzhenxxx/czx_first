#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x,i=0;
    vector<int>s(10,0);
    while(cin>>x)
     {
     int n;
         auto iter=s.begin();
         if(x>100)
         {
             cout<<"wrong"<<endl;
             continue;
         }
         n=x/10;
         iter+=n;
         (*iter)++;
     }
     for(auto c :s)
      {
          cout<<c<<endl;
      }
}