#include<stdio.h>
int dp[1000];
 int from[1000];int a[1000];

void out(int pos)
{
    if(pos==0)
    return ;
    out(from[pos]);
    printf("%d ",a[pos]);
}
int main()
{
    int n;
    
   
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
      dp[i]=1;
      from[i]=0;
     for(int j=1;j<i;j++)
      {
          if(a[j]<a[i]&&dp[i]<dp[j]+1)
          {
              from[i]=j;
              dp[i]=dp[j]+1;
          }
      }
    }
    int max=dp[1],pos=1;
    for(int i=1;i<=n;i++)
    {
        if(max<dp[i])
        {
        max=dp[i];
         pos=i;
        }
    }
    printf("%d",max);
    out(pos);
    
}