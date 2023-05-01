#include<iostream>
using namespace std;
int n;
void dfs(int step,int state)
{
    if(step==n)
    {
        for(int i=0;i<n;i++)
        {
            if(state>>i&1)
            {
                cout<<i+1<<" ";
            }
        }
        cout<<endl;
        return;
    }
    dfs(step+1,state);
    dfs(step+1,state|1<<step);
}
int main()
{  
   cin>>n;
   dfs(0,0);
 
}