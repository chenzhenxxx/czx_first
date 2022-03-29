#include<iostream>
using namespace std;
int a[1000][1000];
int b[1000][1000];
int main()
{
   int n,m;
   cin>>n>>m;
   for(int i=0;i<n;i++)
   for(int j=0;j<m;j++)
   cin>>a[i][j];
   for(int i=0;i<n;i++)
   for(int j=0;j<m;j++)
   cin>>b[i][j];
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           a[i][j]=a[i][j]+b[i][j];
          printf("%d ",a[i][j]);
       }
       printf("\n");
   }
}