#include<iostream>
#include<cstring>
#include<vector>

#define  PLL pair<int,int>

using namespace std;

int turn[4][4];

int get(int x,int y)
{
    return x*4+y;
}

int main()
{
    int state=0;
    for(int i=0;i<4;i++)
    {
        string line;
        cin>>line;
        for(int j=0;j<4;j++)
        {
            if(line[j]=='+')
            {
                state+=1<<get(i,j);
            }
        }
    }

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {   for(int k=0;k<4;k++)
            {
            turn[i][j]+=1<<get(i,k);
            turn[i][j]+=1<<get(k,j);
            }
            turn[i][j]-=1<<get(i,j);
        }
    }
    vector<PLL> ans;
    for(int i=0;i<2<<16;i++)
    {   vector<PLL> tmp;
        int k=state;
        for(int j=0;j<16;j++)
        {
            if(i&1<<j)
            {   int a=j/4,b=j%4;
                k^=turn[a][b];
                tmp.push_back({a,b});
            }
        }
        if(!k&&(ans.empty()||ans.size()>tmp.size()))  ans=tmp;
    }
    cout<<ans.size()<<endl;
    for(auto &i:ans)
    {
        cout<< i.first+1<<" "<<i.second+1<<endl;
    }
}