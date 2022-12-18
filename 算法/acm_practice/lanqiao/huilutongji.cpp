#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int g[22][22],visit[22];
int ans=0,cnt=0;
void judge(int x,int y)
{
    for(int i=1;i<=y;i++)
     if(y%i==0&&x%i==0&&i!=1)
      {
        return;
      }
      g[x][y]=g[y][x]=1;
}
void dfs(int k)
{  
    printf(" %d %d\n",cnt,k);
   if(cnt==21&&k==1)
   {
      printf("%d\n",ans);
    ans++;
    return;
   }
   else if(cnt==21)
   return;

   for(int i=1;i<=21;i++)
   {
    if(i==1&&cnt!=20)
    {
        continue;
    }
    if(!visit[i]&&g[k][i])
    {   printf("%d->%d",k,i);
        visit[i]=1;
        cnt++;
        dfs(i);
        visit[i]=0;
        cnt--;
    }
   }
   return;
}
int main()
{
      for(int i=1;i<=21;i++)
       for(int j=1;j<i;j++)
       {  
          judge(i,j);
       }
    //    for(int i=1;i<=21;i++)
    //    { 
    //    for(int j=1;j<21;j++)
    //    {  
    //       printf("%d",g[i][j]);
    //    }
    //    printf("\n");
    //    }
       dfs(1);
       printf("%d\n",ans);

}