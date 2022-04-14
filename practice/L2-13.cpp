#include<iostream>
#include<cstring>
using namespace std;
int f[1000];
int book[1000];
struct node
{
    int x;
    int y;
}city[6000];
int find(int x)
{
       return x==f[x]?f[x]:find(f[x]);
}
void merge(int a,int b)
{
    int c=find(a);
    int d=find(b);
    if(c!=d)
     {
         f[c]=d;
     }
}
int main()
{
    int n,m,k;
    int num1=0,num2;
    cin>>n>>m;
    for(int i=0;i<n;i++)
      {
          f[i]=i;
      }
      for(int i=0;i<m;i++)
        {   int u,v;
           scanf("%d %d",&u,&v);
            city[i].x=u;
            city[i].y=v;
           merge(u,v);
        }
        for(int i=0;i<n;i++)
         {
             if(f[i]==i)
              num1++;
         }
        
         cin>>k;
          memset(book,0,sizeof(book));
         while(k--)
          {   num2=0;
              int a;
              cin>>a;
              
              for(int i=0;i<n;i++)
               {
                   f[i]=i;
               }
              book[a]=1;
              for(int i=0;i<m;i++)
               {
                   if(book[city[i].x]==1||book[city[i].y]==1)
                    {
                        continue;
                    }
                    else merge(city[i].x,city[i].y);
               }
               num2=0;
               for(int i=0;i<n;i++)
                {
                    if(f[i]==i)
                     num2++;
                }
                if(num1==num2||num1+1==num2)
                 {
                     printf("City %d is lost.\n",a);
                 }
                 else
                 printf("Red Alert: City %d is lost!\n",a);
                 num1=num2;
          }
          int i,num=0;
          for( i=0;i<n;i++)
           {
               if(book[i]==0)
                break;
                num++;
           }
           if(num==n)
           printf("Game Over.");
}