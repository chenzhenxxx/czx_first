#include <bits/stdc++.h>
using namespace std;
int mapp[14][14];
int h[14];
int l[14];
int lx[50];
int rx[50];
int jl[14];
int ans=0;
int n; 
void dfs(int x)
{
    if(x>n)
    {
        ans++;
        if(ans<=3)
        {
            for(int i=1;i<=n;i++)
            {
                cout<<jl[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    for(int j=1;j<=n;j++){
        if(h[x]==0&&l[j]==0&&lx[x-j+n]==0&&rx[x+j]==0)
        {   h[x]=1;
            l[j]=1;
            lx[x-j+n]=1;
            rx[x+j]=1;
            jl[x]=j;
            dfs(x+1);
            h[x]=0;
            l[j]=0;
            lx[x-j+n]=0;
            rx[x+j]=0;
            jl[x]=0;

        }
    }

}
int main()
{
    cin>>n;
    dfs(1);
    cout<<ans<<endl;
    return 0;

}