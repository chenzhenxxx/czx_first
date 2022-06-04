#include<bits/stdc++.h>
using namespace std;
map<int,map<int,int>> box;
int main()
{
    int n,q;
    cin>>n>>q;
    while(q--)
    {
        int k,x,y;
        scanf("%d %d %d",&k,&x,&y);
        if(k==1)
        {   int num;
            scanf("%d",&num);
            box[x][y]=num;

        }
        else
        {
            printf("%d\n",box[x][y]);
        }
    }
}