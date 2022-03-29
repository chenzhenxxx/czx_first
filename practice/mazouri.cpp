#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int mx[9]= {-2 , -2 , -1 , -1 , 1 , 1, 2 , 2 } ; 
int my[9]= {-1 , 1 , -2 , 2 , -2 , 2 , -1 , 1 } ; 
int book[200][200];
int n,m,step,cnt;
void dfs(int x,int y,int step)
{
   if(step==n*m)
   {
     cnt++;
     return;
   }
   for(int i=0;i<8;i++)
   {
     int tx,ty;
     tx=x+mx[i];
     ty=y+my[i];
     if(tx<0||tx>=n||ty<0||ty>=m||book[tx][ty]!=0)
     continue;
     if(book[tx][ty]==0)
     {
       book[tx][ty]=1;
       dfs(tx,ty,step+1);
       book[tx][ty]=0;
     }
   }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    { memset(book,0,sizeof(book));
      int x,y;
      cin>>n>>m>>x>>y;
      book[x][y]=1;
      
      cnt=0;
      dfs(x,y,1);
      printf("%d\n",cnt);


    }
}