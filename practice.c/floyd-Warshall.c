#include<stdio.h>
main()
{  
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n+1][n+1];
    int i,j,k;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
      if(i==j)
      a[i][j]=0;
      else
       a[i][j]=999999;
    }
    

     for(i=1;i<=m;i++)
     {
         int x,y,w;
         scanf("%d %d %d",&x,&y,&w);
         a[x][y]=w;
     }
 
     for(k=1;k<=n;k++)
     for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
     if(a[i][j]>a[i][k]+a[k][j])
     a[i][j]=a[i][k]+a[k][j];

     for(i=1;i<=n;i++)
     {
         for(j=1;j<=n;j++)
       printf("%d",a[i][j]);
       printf("\n");
     }

}