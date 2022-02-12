#include<iostream>
#include<algorithm>

using namespace std;

int main()
{

    int ft,fq,st,sq;
    int t[1001],q[1001];
    int n,i;
    while(scanf("%d",&n)==1&&n!=0)
    {  int cnt=0,ans=0;
    for(i=0;i<n;i++)
        cin>>t[i];
    for(int j=0;j<n;j++)
        cin>>q[j];
       sort(t,t+n);
       sort(q,q+i);
    
       ft=n-1;
       fq=n-1;
       st=0;
       sq=0;
       while(cnt++<n)
       {
          if(t[ft]>q[fq])
          {
              ft--;
              fq--;
              ans++;
          }
          else if(t[ft]<q[fq])
          {
              st++;
              fq--;
              ans--;
          }

          else
          {
              if(t[st]>q[sq])
              {
                  st++;
                  sq++;
                  ans++;
              }
              else if(t[st]<q[sq])
              {
                  st++;
                  fq--;
                  ans--;
              }
              else
              {
                  if(t[st]<q[fq])
                  {
                      st++;
                      fq--;
                      ans--;
                  }
                
              }
          }
       }
       printf("%d\n",ans*200);

    }

}