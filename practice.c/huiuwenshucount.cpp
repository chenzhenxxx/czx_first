#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int a[11];
    a[1]=9;
    for(i=2;i<=n;i++)
    {
        if((i+1)%2==0)
        a[i]=a[i-1]*10;
        else
        a[i]=a[i-1];
    }
    int sum=0;
    for(i=1;i<=n;i++)
    sum+=a[i];

    cout<<sum;
}