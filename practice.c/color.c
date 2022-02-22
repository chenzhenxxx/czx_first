 #include <stdio.h>
 int book[50][50]={0};
 int n;
 int a[50][50];
 void dfs(int x,int y)
 {
     if(x<1||x>n||y>n||y<1||a[x][y]!=0||book[x][y]!=0)
     return ;
     book[x][y]=-1;
     dfs(x+1,y);
     dfs(x-1,y);
     dfs(x,y-1);
     dfs(x,y+1);
 }
 main()
 {
     int i,j,k,h;
     scanf("%d",&n);
     
     for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
     {
         scanf("%d",&a[i][j]);
         if(a[i][j]==1)
         book[i][j]=1;
     }

     for(i=1;i<=n;i++)
     {
         if(a[i][1]!=1)
         dfs(i,1);
         if(a[i][n]!=1)
         dfs(i,n);
     }

     for(j=1;j<=n;j++)
     {
         if(a[1][j]!=1)
         dfs(1,j);
         if(a[n][j]!=1)
         dfs(n,j);
     }
     for(i=1;i<=n;i++)
     {
         for(j=1;j<=n;j++)
          {
              if(book[i][j]==1)
              printf("1 ");
              else if(book[i][j]==-1)
              printf("0 ");
              else 
              printf("2 ");
          }
          printf("\n");
     }
 }
     
     
     
    