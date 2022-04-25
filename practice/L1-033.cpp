#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main()
{
    int year,n;
    cin>>year>>n;
    for(int i=year;i<=year+150;i++)
     {
         s.clear();
         int a=i/1000;
         int b=i/100%10;
         int c=i/10%10;
         int d=i%10;
         s.insert(a);
         s.insert(b);
         s.insert(c);
         s.insert(d);
         if(s.size()==n)
         {
             printf("%d %04d",i-year,i);
             break;
         }
     }
}