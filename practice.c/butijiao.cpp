#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    while(n--)
    {  int m,ka;
       int a[110];
       a[0]=0;
       cin>>m>>ka;
       a[m+1]=101;
       for(i=1;i<=m;i++)
       cin>>a[i];
       if(ka>=m)
       printf("100\n");
       else
       {
       
       int maxx=0;
       for(i=ka+1;i<=m+1;i++)
       {
           if((a[i]-a[i-ka-1]-1)>=maxx)
           maxx=a[i]-a[i-ka-1]-1;
       }
       printf("%d\n",maxx);
       }
    }
}