#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char path[6][6];
int dx[5]={0,0,0,-1,1};
int dy[5]={-1,1,0,0,0};
void turn(int x,int y)
{
   for(int i=0;i<5;i++)
   {
      int tx=x+dx[i];
      int ty=y+dy[i];
      if(tx>=0&&tx<5&&ty>=0&&ty<5)
      {
        path[tx][ty]^=1;
      }
   }
}
int judge()
{   int res=10000000;
    for(int i=0;i<32;i++)
    {    int step=0;
        char tmp[6][6];
         memcpy(tmp,path,sizeof(path));
        for(int j=0;j<5;j++)
        {
            if(i>>j&1)
            {
                step++;
                turn(0,j);
            }
        }
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(path[i][j]=='0')
                {   step++;
                    turn(i+1,j);
                }
            }
        }
        int flag=0;
        for(int i=0;i<5;i++)
        {
            if(path[4][i]!='1')
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        res=min(step,res);
        memcpy(path,tmp,sizeof(tmp));
    }
    if(res>6) res=-1;
    return res;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
       for(int i=0;i<5;i++) cin>>path[i];
       cout<<judge()<<endl;
    }
}