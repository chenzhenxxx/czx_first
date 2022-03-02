#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int f[20][20];
int n;
int main()
{
    memset(f,0,sizeof(f));
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
       f[i][0]=1;
    for(int j=1;j<=n;j++)
       for(int i=0;i<=n;i++)
       
        {
          if(i>=1) 
            f[i][j]=f[i-1][j]+f[i+1][j-1];
          if(i==0)
            f[i][j]=f[i+1][j-1];
        }
    printf("%d",f[0][n]);
    return 0;
}