#include<iostream>
#include<cstring>
using namespace std;
#define N 100100
int f[N],g[10];
int main()
{
    int n,res=0;
    cin>>n;
     
        for(int i=0;i<n;i++)
        {   char num[20];
            scanf("%s",&num);
            int r=num[strlen(num)-1]-'0',l=num[0]-'0';
            f[i]=max(1,g[l]+1);
            g[r]=max(f[i],g[r]);
            res=max(res,f[i]);
        }
    cout<<n-res<<endl;
    
}