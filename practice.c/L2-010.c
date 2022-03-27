#include<stdio.h>
int map[110][110];
main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++)
     {
         int x,y,w;
         scanf("%d %d %d",&x,&y,&w);
         map[x][y]=map[y][x]=w;
     }
      for(int i=0;i<k;i++)
       {
           int x,y;
           scanf("%d %d",&x,&y);
            if(map[x][y]==1)
            printf("No problem\n");
            else if(map[x][y]==0)
            printf("OK\n");
            else
             {   int flag=0;
                 for(int j=1;j<n;j++)
                  {
                      if(map[x][j]==1&&map[y][j]==1)
                       {
                           flag=1;
                           break;
                       }
                  }
                  if(flag==0)
                  printf("No way\n");
                  else
                  printf("OK but...\n");
             }
       }
}