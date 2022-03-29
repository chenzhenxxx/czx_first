#include<iostream>
#include<algorithm>
using namespace std;
char mi[200][200];
int book[200][200];
int n,m,sx,sy,zx,zy,flag=0;
int a[4]={0,0,1,-1},b[4]={1,-1,0,0};
void dfs(int x,int y)
{   int tx,ty;
    if(x==zx&&y==zy)
    {
        flag=1;
        printf("yes\n");
        exit(0);
    }
    for(int i=0;i<4;i++)
    {
        tx=x+a[i];ty=y+b[i];
        if(tx>=0&&tx<n&&ty>=0&&ty<m&&book[tx][ty]==0&&mi[tx][ty]!='*')
        {   book[tx][ty]=1;
            dfs(tx,ty);
            book[tx][ty]=0;
        }

    }


}
int main()
{    
     cin>>n>>m;
     int i,j;
     for(i=0;i<n;i++)
     for(j=0;j<m;j++)
      {
          cin>>mi[i][j];
          if(mi[i][j]=='S')
          {
              sx=i;
              sy=j;
              
          }
          if(mi[i][j]=='T')
          {
              zx=i;
              zy=j;
          }
      }
      dfs(sx,sy);
      if(!flag)
      printf("no\n");
}