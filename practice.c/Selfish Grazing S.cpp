#include<iostream>
#include<algorithm>
using namespace std;
struct cow
{
    int r;
    int l;
}niu[50005];
bool cmp(cow a,cow b)
{
    return (a.r<b.r);
}

int main()
{
    int n,i,j,count=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>niu[i].l>>niu[i].r;
    sort(niu+1,niu+n+1,cmp);

    int ans=0;
    for(i=1;i<=n;i++)
    {
        if(ans<=niu[i].l)
        {
            count++;
            ans=niu[i].r;
        }
    }
    cout<<count;
    return 0;

}