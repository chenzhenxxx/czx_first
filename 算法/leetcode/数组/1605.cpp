#include <bits/stdc++.h>
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int mapp[11][11];
int used[11][11];
int sx,sy,fx,fy;
int n,m,t;
int ans=0;
void dfs(int x,int y){
    if(x==fx&&y==fy)
    {
        ans++;
        return;
    }
    for(int i=0;i<4;i++){
        int tmp_x=x+dx[i];
        int tmp_y=y+dy[i];
        if(tmp_x>=1&&tmp_x<=n&&tmp_y>=1&&tmp_y<=m&&used[tmp_x][tmp_y]==0&&mapp[tmp_x][tmp_y]==0){
            used[tmp_x][tmp_y]=1;
            dfs(tmp_x,tmp_y);
            used[tmp_x][tmp_y]=0;
        }
    }

}
int main(){
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    for(int i= 0; i<t;i++)
    {
        int tmpx,tmpy;
        cin>>tmpx>>tmpy;
        mapp[tmpx][tmpy]=1;
    }
    used[sx][sy]=1;
    dfs(sx,sy);
    cout<<ans<<endl;
}