#include <iostream>
#include<algorithm>
using namespace std;
int book[200][200]={0};
int dx[10]={0,0,0,1,-1,1,-1,-1,1};
int dy[10]={0,1,-1,0,0,1,-1,1,-1};
int cnt,n,m,flag;
char water[200][200];
void dfs(int x,int y)
{    
     int i,j;
     for(i=0;i<9;i++)
     {
         int tx,ty;
         tx=x+dx[i];
         ty=dy[i]+y;
         if(tx<0||tx>=n||ty<0||ty>=m)
         continue;
         if(book[tx][ty]==0&&water[tx][ty]=='W')
           {
               book[tx][ty]=1;
               flag=1;
               dfs(tx,ty);
                
           }
     }
     return;
}
int main()
{
    
    cin>>n>>m;
    int i,j;
    for(i=0;i<n;i++)
     for(j=0;j<m;j++)
      cin>>water[i][j];

       for(i=0;i<n;i++)
     for(j=0;j<m;j++)
      {    flag=0;
       if(book[i][j]==0)
          dfs(i,j);
          if(flag==1)
         cnt++;
      }
      cout<<cnt;
}