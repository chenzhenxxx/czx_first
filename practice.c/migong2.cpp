#include<iostream>
#include<algorithm>
using namespace std;
int n,m,sx,sy,zx,zy,flag=0;
char mi[200][200];
int book[200][200];
struct queue
{
    int x;
    int y;
    int s;
};
int main()
{
     
     cin>>n>>m;
     int i,j;
    
     for(i=0;i<n;i++)
     for(j=0;j<m;j++)
      {
          cin>>mi[i][j];
          
          if(mi[i][j]=='@')
          {
              sx=i;
              sy=j;
             
          }
      }
      int head,tail;
      head=1;
      tail=1;
       struct queue que[10010];
       que[tail].x=sx;
       que[tail].y=sy;
       que[tail].s=0;
       book[sx][sy]=1;
       tail++;
       while(head<tail)
       {  int tx,ty;
          for(int i=0;i<4;i++)
          {   int a[4]={0,0,1,-1},b[4]={1,-1,0,0};
            tx=que[head].x+a[i];
            ty=que[head].y+b[i];
            if(tx<0||tx>=n||ty<0||ty>=m)
            continue;
            if(mi[tx][ty]!='#'&&book[tx][ty]==0)
            {
                book[tx][ty]=1;
                 que[tail].x=tx;
                 que[tail].y=ty;
                 que[tail].s=que[head].s+1;
                 tail++;
            }
          

            if((tx==0||tx==n-1)&&mi[tx][ty]=='.')
            {
                flag=1;
                break;
            }
             if((ty==0||ty==m-1)&&mi[tx][ty]=='.')
            {
                flag=1;
                break;
            }
          }
          if(flag==1)
          break;
          head++;
       }
       if(flag==1)
       cout<<que[tail-1].s;
       else
       printf("-1");
     
}