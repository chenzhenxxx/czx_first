#include<iostream>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{  int n,m;
   cin>>n>>m;
   getchar();
   int cnt=0;
   int i=0;
   string s[100];
   for( i=0;i<n;i++)
    {
       getline(cin,s[i]);
       
    }
    
    for( i=0;i<n;i++)
     {
         if(s[i].find("easy")!=-1||s[i].find("qiandao")!=-1)
         continue;
         else 
         cnt++;
         if(cnt==m)
         {
             break;
         }
     }
     if(i==n)
     {
         printf("Wo AK le");
     }
     
     else
     {
         for(int j=i+1;j<n;j++)
         {
             if(s[i].find("easy")!=-1||s[i].find("qiandao")!=-1)
         continue;
         else 
         {
             cout<<s[j];
             break;
         }
         }
     }
}