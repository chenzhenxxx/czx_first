#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<set>
using namespace std;
set<int> s[55];
int main()
{
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
     {
         int x;
         cin>>x;
         while(x--)
          {
              int y;
              cin>>y;
              s[i].insert(y);
          }
     }
     int h;
     cin>>h;
     while(h--)
     {
         int a,b;
         cin>>a>>b;
         int l1=s[a].size(),l2=s[b].size();
         int l3=0;
         for(set<int>::iterator it=s[a].begin();it!=s[a].end();it++)
          {
              if(s[b].find(*it)!=s[b].end())
              {
                  l3++;
              }
          }
          printf("%.2f%%\n",l3*1.0/(l1+l2-l3)*100);
     }  
}