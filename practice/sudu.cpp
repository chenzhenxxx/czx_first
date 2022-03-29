#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int h[10][10];
int l[10][10];
int block[10][10];
char s[10][10];
int a[10][10];
bool judge;
bool dfs(int x,int y)
{   bool flag=false;
    if(x==9)
    return true;
    if(a[x][y])
    {
        if(y==8)
        flag=dfs(x+1,0);
        else
         flag=dfs(x,y+1);
         return flag;
    }
    int m=x/3*3+y/3;
    for(int i=1;i<=9;i++)
    {
        if(h[x][i]==0&&l[y][i]==0&&block[m][i]==0)
        {
            h[x][i]=1;
            l[y][i]=1;
            block[m][i]=1;
            a[x][y]=i;
            if(y==8)
            flag=dfs(x+1,0);
            else
            flag=dfs(x,y+1);
            if(flag)
            return true;
            else
            {
                h[x][i]=0;
                l[y][i]=0;
                block[m][i]=0;
                a[x][y]=0;
            }
            
        }
    }
     return false;
}
int main()
{
   int n;
   cin>>n;
   while(n--)
   {  
        memset(h,0,sizeof(h));
        memset(l,0,sizeof(l));
        memset(block,0,sizeof(block));
      for(int i=0;i<9;i++)
       cin>>s[i];

       for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            a[i][j]=s[i][j]-'0';
            if(a[i][j]!=0)
            {
            int m=(i/3)*3+j/3;
            block[m][a[i][j]]=1;
            h[i][a[i][j]]=1;
            l[j][a[i][j]]=1;
            }
        }

       
        
        dfs(0,0);
       
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            cout<<a[i][j];
            printf("\n");
        }
         
   }
}