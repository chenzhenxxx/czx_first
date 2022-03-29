#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n,sum=0;
    char a[101];
    int c[101];
    cin>>n;
    cin>>a;
    for(int i=0;i<n;i++)
    {
        c[i]=a[i]-'0';
        sum+=c[i];
    }
    int k,current_d,cs,flag=0;
    for(k=0;k<=sum;k++)
    {
         cs=0,current_d=0,flag=0;
        for(int i=0;i<n;i++)
         {
             cs+=c[i];
             if(cs==k)
             {
                 current_d++;
                 cs=0;
                 continue;
             }
             if(cs>k)
             {    flag=1;
                 break;
             }
         }
         if(current_d>1&&!flag&&cs!=0)
         {
             printf("YES\n");
             return 0;
         }
    }
    printf("NO\n");
}