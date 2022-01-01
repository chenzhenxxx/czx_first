#include<stdio.h>
struct queue 
{
    int x;
    int y;
    int f;
    int s;
};
   int a[51][51];
     int book[51][51];
main()
{  
     struct queue que[2501];
  
     int n,m,startx,starty,p,q,i,j,flag=0;
     scanf("%d %d",&n,&m);
     for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
     scanf("%d",&a[i][j]);
     
     scanf("%d %d %d %d",&startx,&starty,&p,&q);
     int head,tail;
     head=1;
     tail=1;
     que[tail].x=startx;
     que[tail].y=starty;
     que[tail].f=0;
     que[tail].s=0;
     tail++;
     book[startx][starty]=1;                                      
     while(head<tail)
     {   
         int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
         int tx,ty;
         for(int i=0;i<=3;i++)
         {
             tx=que[head].x+next[i][0];
             ty=que[head].y+next[i][1];
             if(tx<1||tx>n||ty<1||ty>m)
             continue;
             if(book[tx][ty]==0&&a[tx][ty]==0)
             {
                 book[tx][ty]=1;
                 que[tail].x=tx;
                 que[tail].y=ty;
                 que[tail].f=head;
                 que[tail].s=que[head].s+1;
                 tail++;
             }


             if(tx==p&&ty==q)
              {
               flag=1;
               break;
              }


         }
         if(flag==1)
         break;
         head++;
         
         
     }

     printf("%d",que[tail-1].s);

}