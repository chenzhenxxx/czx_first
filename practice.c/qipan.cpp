#include<iostream>
#include<algorithm>
#include<cstring>
char q[20][20];
int h[20];
int m,cnt;
int n,k;
using namespace std;
void dfs(int x,int m)
{    if(m>=k)
     {
         cnt++;
         return;
     }
     int i,j;
     for(i=x;i<n;i++)
     for(j=0;j<n;j++)
     {
         if(q[i][j]=='#'&&h[i]==0)
         {
             h[j]=1;
             dfs(i+1,m+1);
              h[j]=0;
         }
     }
}
int main()
{
    while(scanf("%d %d",&n,&k)==2&&n!=-1&&k!=-1)
    {  
       memset(q,0,sizeof(q));
       memset(h,0,sizeof(h));
       
       cnt=0;
       for(int i=0;i<n;i++)
       cin>>q[i];
        
        dfs(0,0);
        printf("%d\n",cnt);


    }
}