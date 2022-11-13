#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cout << "请输入行数";
    cin >> m;
    cout << "请输入列数";
    cin >> n;
    int a[m + 1][n + 1];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    int max, min, p, q;
    for (int i = 1; i <= m; i++)
    {   int flag=0;
        min = a[i][1];
        p = 1;
        for (int j = 1; j <= n; j++)
        {
            if (min > a[i][j])
            {
                min = a[i][j];
                p = j;
            }
        }
        for (int k = 1; k <= m; k++)
        {
            if (min < a[k][p])
            {   flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<min<<" ";
        }
    }
}