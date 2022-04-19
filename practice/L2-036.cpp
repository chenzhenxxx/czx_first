#include<bits/stdc++.h>
using namespace std;
int a[250][250]={0};
int book[250];
int main()
{
    int n,m,ans=0,min_sum=9999999,index=1;
    cin>>n>>m;
    for(int i=0;i<m;i++)
     {
         int b,c,d;
         cin>>b>>c>>d;
         a[b][c]=d;
         a[c][b]=d;
     }
     int k;
     cin>>k;

     for(int j=1;j<=k;j++)
      {   
          int h,flag=0,sum=0,i;
          memset(book,0,sizeof(book));
          cin>>h;
          int tmp=0;
          for( i=0;i<h;i++)
           {    
               int tmpp;
               cin>>tmpp;
              
               if(a[tmp][tmpp]==0||book[tmpp]||h!=n)
                {   flag=1;
                    continue;
                }
                 else
                 {
                 book[tmpp]=1;
                sum+=a[tmp][tmpp];
                 }
                 tmp=tmpp;

           }
           if(a[tmp][0]==0)
            {
                flag=1;
            }
            else
             {
                 sum+=a[tmp][0];
             }
           if(flag==0)
           ans++;
           if(min_sum>sum&&flag==0)
            {
                min_sum=sum;
                index=j;
            }
           
      }
        printf("%d\n",ans);
        printf("%d %d",index,min_sum);
      
}