#include<stdio.h>
int n,k;
int a[21];
int total;
int sum=0;
void dfs(int step,int sum,int t )
{   
    int flag=1;
    int m,i;
    if(step==(k+1))
    {   
        for( m=sum-1;m>1;m--)
         {
             if(sum%m==0)
         {   
             flag=0;
             break;
         }
         }
         if(flag)
        {
         
             total++;
         
        }
        
         return;
    }

    for(i=t;i<n;i++)
    {
        
          dfs(step+1,sum+a[i],i+1);
    }
    return;
          
         

}
main()
{   int j;
    scanf("%d %d",&n,&k);
    for(j=0;j<n;j++)
    scanf("%d",&a[j]);
    
    dfs(1,0,0);
    printf("%d",total);

}