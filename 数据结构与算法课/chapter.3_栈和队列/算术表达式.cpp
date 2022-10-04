#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef struct stacknode
{
    struct stacknode *next;
    double data;
} nStack, *nStacklink;
typedef struct sstacknode
{
    struct sstacknode *next;
    char data;
} sStack, *sStacklink;

nStack *num;  //数字栈
sStack *sym;  //符号栈
map<char, int> level;

void Push_num(nStack *num, double sum);
char GetTop(sStack *sym);
void Push_sym(sStack *sym, char c);
void Pop_sym();
double Pop_num();
double deal(char c);
void Get_detail();
void Init();

int main()
{
    
    Init();  //初始
    Get_detail();//获取数据并处理
}

void Init() //初始化
{
    level['#'] = 0;    //符号优先级
    level['+'] = 1;
    level['-'] = 1;
    level['*'] = 2;
    level['/'] = 2;
    level['^'] = 3;
    level['('] = 4;
    level[')'] = 4;
    sym = (sStack *)malloc(sizeof(sStack));
    sym->next = NULL;
    num = (nStack *)malloc(sizeof(nStack));
    num->next = NULL;
    sStack *p = (sStack *)malloc(sizeof(sStack));
    p->data = '#';  //先压一个#方便判断结束。
    p->next = sym->next;
    sym->next = p;
}

void Push_num(nStack *num, double sum)  //压数字栈
{
    nStack *p = (nStack *)malloc(sizeof(nStack));
    p->data = sum;
    p->next = num->next;
    num->next = p;
    return;
}
char GetTop(sStack *sym)  //获取符号栈栈顶
{
    if (sym->next == NULL)
        return '?';
    else
        return sym->next->data;
}

void Push_sym(sStack *sym, char c)  //压符号栈
{
    sStack *p = (sStack *)malloc(sizeof(sStack));
    p->data = c;
    p->next = sym->next;
    sym->next = p;
}
void Pop_sym()
{
    if (sym->next != NULL)
    {
        sStack *p = sym->next;
        sym->next = p->next;
        free(p);
    }
}
double Pop_num()
{
    if (num->next != NULL)
    {
        double x = num->next->data;
        nStack *p = num->next;
        num->next = p->next;
        free(p);
        return x;
    }
    return 0;
}
double  deal(char c)
{
    double x = Pop_num();
    double y = Pop_num();

    double data = 0;
    switch (c)
    {
    case '+':
        data = x + y;

        break;
    case '-':
        data = y - x;
        break;
    case '*':
        data = x * y;
        break;
    case '/':
        data = y / x;

        break;
    case '^':
        data = pow(y, x);
    }
    return data;
}
void Get_detail()
{
    string s;
    printf("请输入表达式:\n");
    cin >> s;
    s += '#';
    int len = s.size(), count = 0;
    while (1)
    {
        double sum = 0;
        while (isdigit(s[count]))
        {
            sum = sum * 10 + s[count] - '0';
            count++;
        }
        if (s[count] == '.')
        {
            int k = 1;
            count++;
            while (isdigit(s[count]))
            {
                sum = sum + (s[count] - '0') * pow(0.1, k);
                k++;
                count++;
            }
        }
        if (sum != 0)
            Push_num(num, sum);
        if (!isdigit(s[count]))
        {
            char c = GetTop(sym);

            if (c == '?' || c == '(')
            {
                Push_sym(sym, s[count]);
                count++;
            }

            else if (s[count] == ')')
            {
                char c = GetTop(sym);
                while (c != '(')
                {
                    double data = deal(c);
                    Pop_sym();

                    Push_num(num, data);

                    c = GetTop(sym);
                }
                Pop_sym();
                count++;
            }
            else if (level[c] == level[s[count]] && (c == '*' || c == '/' || c == '+' || c == '-'))
            {
                double data = deal(c);
                Pop_sym();

                Push_num(num, data);
                Push_sym(sym, s[count]);
                count++;
            }
            else if (level[c] == level[s[count]] && (c == '#'))
            {
                break;
            }
            else if (level[c] > level[s[count]])
            {
                if (c == '(')
                {
                    Push_sym(sym, s[count]);
                    count++;
                    continue;
                }
                char c = GetTop(sym);

                double data = deal(c);
                Pop_sym();

                Push_num(num, data);
            }
            else
            {
                Push_sym(sym, s[count]);
                count++;
            }
        }
    }

    cout << num->next->data << endl;
}