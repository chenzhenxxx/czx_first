#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int a[n];
        for(int i=1;i<=n;i++)
         cin>>a[i];
        
         int cnt=1,tili=m;
         int ans=1;
         while(cnt<=n)
         {    
             int d=min(a[cnt],tili);
             tili-=d;
             a[cnt]-=d;
             if(tili>=0)
             {  
             if(cnt+1>n)
              break;
              cnt++;
                if(tili<=k)
                 {   
                     ans++;
                     tili=m;
                 }
                 else tili-=k;
             }
             else
             {
                 ans++;
                 tili=m;
             }

         }
         cout<<ans<<endl;
    }
}