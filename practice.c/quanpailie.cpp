#include<iostream>
#include<cstring>
using namespace std;
int book[15];
char ans[15];
char m[15];
int n;
void dfs(int step)
{
    if(step>n)
    {
        for(int i=1;i<=n;i++)
        printf("%c",ans[i]);
        printf("\n");
        return;
    }

    for(int j=0;j<n;j++)
    {
        if(book[j]==0)
        {
            ans[step]=m[j];
            book[j]=1;
            dfs(step+1);
            book[j]=0;
        }
    }
}
int main()
{
    cin>>m;
    n=strlen(m);
    dfs(1);
}