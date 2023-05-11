#include<iostream>
#include<algorithm>
using namespace std;
int func(int a,int b)
{
    for(int i=2;i<=a;i++)
    {
        if(b%i==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int ans=0;
    for(int i=1;i<=2020;i++)
    {
        for(int j=1;j<=2020;j++)
         {  
            if(__gcd(i,j)==1)
            {
                ans++;
            }
         }
    }
    cout<<ans<<endl;
}