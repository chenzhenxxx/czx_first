#include<bits/stdc++.h>
using namespace std;
int total=0,k,n;
int a[100];
void dfs(int step,int sum,int t)
{   int flag=1;
     if(step==(k+1))
     {
         for(int m=sum-1;m>1;m--)
          {
              if(sum%m==0)
              {
                  flag=0;
              }
          }
           if(flag==1)
          total++;
          return;
     }
     for(int i=t;i<n;i++)
      {
          dfs(step+1,sum+a[i],i+1);
      }
      return;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
     cin>>a[i];

     dfs(1,0,0);
     printf("%d",total);
}