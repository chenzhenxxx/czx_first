#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e6+10;
int a[N];
int q[N];
int main()
{
    int n,k,i,j;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    cin>>a[i];
    int head=0,tail=-1;

    //min
    for(i=1;i<=n;i++)
    {
        if(head<=tail&&i-k+1>q[head])head++;
        while(head<=tail&&a[i]<a[q[tail]])
        {
            tail--;
        }
        q[++tail]=i;
        if(i>=k)
        printf("%d ",a[q[head]]);

    }
     printf("\n");

     //max
     head=0,tail=-1;
    for(i=1;i<=n;i++)
    {
        if(head<=tail&&i-k+1>q[head])head++;
        while(head<=tail&&a[i]>a[q[tail]])
        {
            tail--;
        }
        q[++tail]=i;
        if(i>=k)
        printf("%d ",a[q[head]]);

    }
     printf("\n");
}