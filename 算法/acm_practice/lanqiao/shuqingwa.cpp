#include<bits/stdc++.h>
using namespace std;
int weishu(int n)
{
    if(n>=1&&n<=10)
    return 1;
    if(n>=11&&n<=20||n%10==0)return 2;
    return 3;
}
int main()
{   
    int sum=0;
    for(int i=1;i<=20;i++) sum+=weishu(i);
    for(int i=1;i<=20;i++) sum+=weishu(i);
    for(int i=2;i<=40;i+=2) sum+=weishu(i);
    for(int i=4;i<=80;i+=4) sum+=weishu(i);

    cout<<sum+200;
}