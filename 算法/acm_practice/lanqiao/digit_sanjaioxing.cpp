#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int a[256][256];
int b[256][256];
int n;
// int leftcnt=0,rightcnt=0;
// int Find_best(int i,int j)
// {
//     if(i==n)
//     {
//         return a[i][j];
//     }
//     if(leftcnt-rightcnt>1&&path[i+1][j+1]==-1)
//     {
//         rightcnt++;
//         path[i+1][j+1]=Find_best(i+1,j+1);
//     }
//     else if(rightcnt-leftcnt>1&&path[i+1][j]==-1)
//     {
//          leftcnt++;
//         path[i+1][j]=Find_best(i+1,j);
//     }
//     else if(path[i+1][j]==-1)
//     {   leftcnt++;
//         path[i+1][j]=Find_best(i+1,j);
//     }
//     else if(path[i+1][j+1]==-1)
//     {   rightcnt++;
//         path[i+1][j+1]=Find_best(i+1,j+1);
//     }
//     if(path[i+1][j]>path[i+1][j+1])
//     return path[i+1][j]+a[i][j];
//     return path[i+1][j+1]+a[i][j];
// }
// int main()
// {
   
//    cin>>n;
//    memset(path,-1,sizeof(path));
//    for(int i=1;i<=n;i++)
//    for(int j=1;j<=i;j++)
//    {
//     cin>>a[i][j];
//    }
//    cout<<Find_best(1,1);
// }
int main()
{
   cin>>n;
   for(int i=1;i<=n;i++)
   for(int j=1;j<=i;j++)
   {
    cin>>a[i][j];
   }
   b[1][1]=a[1][1];
   for(int i=2;i<=n;i++)
    for(int j=1;j<=i;j++)
    {
        if(j==1)
        {
            b[i][j]=b[i-1][j]+a[i][j];
        }
        else if(j!=1&&j!=i-1)
        {
            b[i][j]=max(b[i-1][j],b[i-1][j-1])+a[i][j];
        }
        else
        {
            b[i][j]=b[i-1][j-1]+a[i][j];
        }

    }
     if(n%2!=0)
     {
        printf("%d",b[n][(n+1)/2]);
     }
     else{
        printf("%d",max(b[n][n/2],b[n][(n+1)/2]));
     }
}