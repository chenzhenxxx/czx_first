#include <bits/stdc++.h>
using namespace std;
void change(int n, int wei)
{
    string s = "";
    while (n > 0)
    {
        if ((n % wei) >= 10)
        {
            int num = 'A' + n % wei - 10;
            char c = num;
            s.push_back(c);
        }
        else
        {
            int num = n % wei + '1' - 1;
            char c = num;
            s.push_back(c);
        }
        n /= wei;
    }
    reverse(s.begin(), s.end());
    cout << s;
}
int main()
{
    int x;
    cin >> x;
    for (int i = 1; i < x; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
            {
                change(i, x);
                printf("*");
                change(j, x);
                printf("=");
                change(i * j, x);
            }
            else
            {
                printf(" ");
                change(i, x);
                printf("*");
                change(j, x);
                printf("=");
                change(i * j, x);
            }
        }
        cout << endl;
    }
}