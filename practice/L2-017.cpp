#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[100100];
    for(int i=0;i<n;i++)
     cin>>a[i];
    sort(a,a+n);
    int sum1,sum2;
    if(n%2==0)
    {
        for(int i=0;i<n/2;i++)
         sum1+=a[i];
         for(int i=n/2;i<n;i++)
         sum2+=a[i];
         printf("Outgoing #: %d\n",n/2);
         printf("Introverted #: %d\n",n/2);
        int diff=fabs(sum2-sum1);
         printf("Diff = %d",diff);
    }
    else 
    {
         for(int i=0;i<n/2;i++)
         sum1+=a[i];
         for(int i=n/2;i<n;i++)
         sum2+=a[i];
         printf("Outgoing #: %d\n",n/2+1);
         printf("Introverted #: %d\n",n/2);
         int diff=fabs(sum2-sum1);
         printf("Diff = %d",diff);
    }


}