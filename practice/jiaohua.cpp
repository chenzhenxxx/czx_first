#include<iostream>
using namespace std;
int a[200];
int flag;
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++)
    {   int r,l;
        cin>>r>>l;
        for(int j=r;j<=l;j++)
         a[j]++;

        
    }
    int m;
    for(m=1;m<=n;m++)
    {
        if(a[m]!=1)
         {   
             printf("%d %d",m,a[m]);
             return 0;
            
         }
    }
    printf("OK\n");
}