#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t,i;
    cin>>t;
    int a[1010];
    while(t--)
    {
        int n,sum=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        while(n>3)
        {
            sum+=min(a[n-1]+a[0]+a[n-2]+a[0],a[1]+a[0]+a[n-1]+a[1]);
            n-=2;
        }
        if(n==3)
        {
            sum+=a[0]+a[1]+a[2];
        }
        if(n==2)
        sum+=a[1];
        if(n==1)
        sum+=a[0];
        printf("%d\n",sum);

    }

}