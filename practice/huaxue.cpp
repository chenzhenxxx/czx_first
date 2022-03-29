#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int cnt,n,m;
int s[200][200];
int step[200][200]={0};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int dfs(int x,int y)
{   if(step[x][y])
    return step[x][y];
    step[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int tx,ty;
        tx=x+dx[i];
        ty=y+dy[i];
        if(s[tx][ty]<s[x][y]&&tx>=0&&tx<n&&ty>=0&&ty<m)
       {   
         step[x][y]=max(step[x][y],1+dfs(tx,ty));
       }
      
    }
    return step[x][y];
}
int main()
{  int max=-1;
   cin>>n>>m;
   for(int i=0;i<n;i++)
   for(int j=0;j<m;j++)
   {
       cin>>s[i][j];
   }
   memset(step,0,sizeof(step));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {   int s=dfs(i,j);
        if(max<s)
        max=s;
    } 
    printf("%d\n",max);
     

}