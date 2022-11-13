#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int k;
    cout<<"右移k位"<<endl;
    cin>>k;
    if(n%k==0)
    {
        return;
    }
    for(int i=1;i<=k;i++)
    {
        int tmp=a[n];
        for(int j=n;j>=1;j--)
        {
            a[j]=a[j-1];
        }
        a[1]=tmp;
    }


  
}