#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int g[8][8], visit[8], father[8];
int ans;

int find_father(int x)
{
    if (x == father[x])
        return x;
    else
        return find_father(father[x]);
}
void dfs(int k)
{
    int t = 0;
    if (k > 7)
    {
        for (int i = 1; i <= 7; i++)
        {
            father[i] = i;
        }

        for (int i = 1; i <= 7; i++)
            for (int j = i; j <= 7; j++)
                if (visit[i] && visit[j] && g[i][j])
                {
                    int a = find_father(i);
                    int b = find_father(j);
                    if (a != b)
                        father[b] = a;
                }

        for (int i = 1; i <= 7; i++)
            if (father[i] == i&&visit[i]==1)
                t++;
        if (t == 1)
            ans++;
        return;
    }
    visit[k] = 1;
    dfs(k + 1);
    visit[k] = 0;
    dfs(k + 1);
}

int main()
{
    g[1][2] = g[1][6] = 1;
    g[2][7] = g[2][3] = 1;
    g[3][7] = g[3][4] = 1;
    g[4][5] = 1;
    g[5][6] = g[5][7] = 1;
    g[6][7]=1;
    dfs(1);
    printf("%d\n", ans);
    // 请在此输入您的代码
    return 0;
}