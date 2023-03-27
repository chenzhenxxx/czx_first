#include<bits/stdc++.h>
using namespace std;
int ml[205];
int visit[205];
int n,a,b;
struct floor{
    int floor;
    int step;
};
void bfs(){
    if(a == b)
    {
        puts("0");
        return;
    }
    queue<struct floor> f;
    f.push((struct floor){a,0});
    visit[a]=1;
    while(!f.empty()){
        struct floor tmp=f.front();
        f.pop();
        if(tmp.floor==b){
            printf("%d\n",tmp.step);
            return;
        }
        for(int i=-1;i<=1;i+=2)
        {   int x=tmp.floor+i*ml[tmp.floor];
            if(x>=1&&x<=n&&visit[x]==0)
            {   visit[x]=1;
                f.push((struct floor){x,tmp.step+1});
            }
        }

    } 
    cout<<"-1"<<endl;

}
int main()
{
   cin>>n>>a>>b;
   for(int i=1;i<=n;i++){
      cin>>ml[i];
   }
   bfs();
}