#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct shi
{
    int v;
       int w;
       float a; 
} ;
bool cmp(struct shi b,struct shi c)
{
    return (c.a<b.a);
}

int main()
{
    int k;
    cin>>k;
    while(k--)
    {   struct shi s[101];
        int total,t;
        double ans=0;
       cin>>total;
       cin>>t;
        
        for(int i=0;i<t;i++)
        {
            cin>>s[i].w>>s[i].v;
            s[i].a=s[i].v*1.0/s[i].w;
        }

        sort(s,s+t,cmp);
        for(int i=0;i<t&&total!=0;i++)
        {
          if(s[i].w<=total)
          {
              total-=s[i].w;
              ans+=s[i].v;
          }
          else
          {  ans+=(total)*s[i].a;
             total=0;
             
          }
        }
        printf("%.2f\n",ans);
    }
        
}