#include<stdio.h>
int dp[100];
int from[100];
int a[10];
void out(int x)
{
    if(x==0)
    return;
    out(from[x]);
    printf("%d ",a[x]);
}
int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
     {
         scanf("%d",&a[i]);
     }
     for(int i=1;i<=n;i++)
      dp[i]=1;

      for(int i=1;i<=n;i++)
       for(int j=1;j<i;j++)
        {
            if(a[j]<a[i]&&dp[i]<dp[j]+1)
             {
                 dp[i]=dp[j]+1;
                 from[i]=j;
             }
        }
         int max=dp[0],tail=0;
        for(int i=1;i<=n;i++)
         {
            if(max<dp[i])
             {
                 max=dp[i];
                 tail=i;
             }
         }
         printf("%d",max);

        out(tail);

}