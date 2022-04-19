#include<iostream>
#include<algorithm>
using namespace std;
struct 
{
    int shu[3];
    int num;
}cx[10010];
int find_ans(int i)
{
    
}
int main()
{
     int n,m,ans=0,cnt=0;
     cin>>n>>m;
     for(int i=0;i<n;i++)
      {   int flag=0;
          int a[m];
          for(int j=0;j<m;j++)
           cin>>a[j];
           for(int h=0;h<=cnt;h++)
           {
                   flag=find_ans(h);
                 if(flag==0)
                   {
                       cx[h].num++;
                   }
           }
            if(flag==1)
             {
                 
                 for(int q=0;q<m;q++)
                  cx[cnt].shu[q]=a[q];
                  cnt++;
             }
              
      }
      for(int i=0;i<=cnt;i++)
       {
           printf("%d",cx[i].num);
           for(int j=0;j<m;j++)
            printf(" %d",cx[i].shu[j]);
            printf("\n");

       }
}