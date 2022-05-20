#include<bits/stdc++.h>
using namespace std;
int big[10],small[10],total[10];
int main()
{

   long long ans=3;
   big[1]=1;
   small[1]=0;
   total[1]=1;
   int cnt=1;
   for(int i=2;i<=6;i++)
    {   cnt++;
        big[i]=big[i-1];
        if(cnt>=4)
        {
            big[i]+=small[i-3];

            
        }
        total[i]=total[i-1]+big[i];
        small[i]=big[i-1];
        ans+=3*total[i];
    }
    long long  n;
    while(cin>>n&&n!=0)
    {
    if(n>=ans)
    cout<<"DAAAAAMN!"<<endl;
    else
    cout<<"AOLIGEI!"<<endl;
    }

   


}