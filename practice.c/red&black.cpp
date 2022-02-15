#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char rb[100][100];
int book[100][100];
int n,m,sx,sy;
int flag;
int cnt;
int step=0;
void dfs(int x,int y)
{  
      step++;
      int tx,ty;
      for(int i=0;i<4;i++)
          {   int a[4]={0,0,1,-1},b[4]={1,-1,0,0};
            tx=x+a[i];
            ty=y+b[i];
            if(tx<0||tx>=n||ty<0||ty>=m)
            continue;
            if(rb[tx][ty]!='#'&&book[tx][ty]==0)
            {
                book[tx][ty]=1;
                dfs(tx,ty);
                
            }
          }
}
int main()
{
    
    while(scanf("%d %d",&m,&n)&&n!=0&&m!=0)
    {  memset(book,0,sizeof(book));
       int i,j;
       for(i=0;i<n;i++)
        for(j=0;j<m;j++)
          {
              cin>>rb[i][j];
              if(rb[i][j]=='@')
              {  
                  sx=i;
                  sy=j;
                  book[i][j]=1;
                  
              }
          }
          step=0;
          flag=1;
          dfs(sx,sy);
          printf("%d\n",step);
          
    }
}