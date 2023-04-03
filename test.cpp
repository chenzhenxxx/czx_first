#include <iostream>
#include <algorithm>
using namespace std;

int P;
char w[36];

string change(int n)
{
    string s;
    while(n)
    {
        s += w[n % P];
        n /= P;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    cin >> P;
    
    for (int i = 0; i <= 9; i ++) w[i] = (char)('0' + i);
    for (int i = 10; i <= 35; i ++) w[i] = (char)('A' + i - 10);
    
    for (int i = 1; i < P; i ++)
    {
        for (int j = 1; j <= i; j ++) cout << w[i] << '*' << w[j] << '=' << change(i * j) << ' ';
        cout << endl;
    }
    
    return 0;
}
