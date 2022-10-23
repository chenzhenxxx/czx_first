#include <iostream>
#include <cstring>
using namespace std;
typedef struct
{
    char ch[512];
    int len;
} String;
int Next[512], nextval[512];

void Get_Next(String t, int *next)
{
    int j = 1, k = 0;
    next[1] = 0;
    while (j < t.len)
    {
        if (k == 0 || t.ch[j] == t.ch[k])
        {
            ++j;
            ++k;
            next[j] = k;
        }
        else
            k = next[k];
    }
}

void Get_Nextval(String t, int next[], int nextval[])
{
    int j = 2, k = 0;
    Get_Next(t, next);
    nextval[1] = 0;
    while (j <= t.len)
    {
        k = next[j];
        if (t.ch[j] == t.ch[k])
        {
            nextval[j] = nextval[k];
        }
        else
            nextval[j] = next[j];
        j++;
    }
}

int Index_KMP(String s, int pos, String ans)
{
    int i = pos, j = 1;
    memset(Next, 0, sizeof(Next));
    memset(nextval, 0, sizeof(nextval));
    Get_Nextval(ans, Next, nextval);
    while (i <= s.len && j <= ans.len)
    {
        if (j == 0 || s.ch[i] == ans.ch[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = nextval[j];
        }
    }
    if (j > ans.len)
        return i - ans.len;
    else
        return 0;
}
int main()
{
    String s1, s2;
    char tmp[512];
    cout << "请输入母串" << endl;
    cin.getline(s1.ch + 1, 512);
    s1.len = strlen(s1.ch + 1);
    cout << s1.len << endl;
    cout << "请输入子串" << endl;
    cin.getline(s2.ch + 1, 512);
    s2.len = strlen(s2.ch + 1);
    cout << "请输入替换串" << endl;
    cin.getline(tmp, 512);
    int pos = 0;
    while ((pos = Index_KMP(s1, 1, s2)) != 0)
    {
        int index = 1;
        char t[512];
        memset(t, 0, sizeof(t));
        for (int i = 1; i < pos; i++)
            t[i] = s1.ch[index++];

        strcat(t + 1, tmp);

        strcat(t + 1, &s1.ch[pos + s2.len]);

        memset(s1.ch + 1, 0, sizeof(s1.ch));
        strcpy(s1.ch + 1, t + 1);
        s1.len = strlen(s1.ch + 1);
        printf("%s\n", s1.ch + 1);
    }
}