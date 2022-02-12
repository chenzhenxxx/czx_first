#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int st[250];
int main()
{
    int n,i,j;
    cin>>n;
    while(n--)
    {
        int k,a,b;
       int ct[440];
       memset(ct,0,sizeof(ct));
        cin>>k;
        for(i=0;i<k;i++)
        {
            cin>>a>>b;
            if(a>b)
            {
                int tmp=a;
                a=b;
                b=tmp;
            }
            a=(a+1)/2;
            b=(b+1)/2;
            for(j=a;j<=b;j++)
            ct[j]++;
        }
        int max=0;
        for(int m=1;m<=220;m++)
        {
            if(max<ct[m])
            max=ct[m];

        }
        printf("%d\n",max*10);
    }

}