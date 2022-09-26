#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef struct stacknode
{
    struct stacknode *next;
    int data;
} nStack, *nStacklink;
typedef struct sstacknode
{
    struct sstacknode *next;
    char data;
} sStack, *sStacklink;
nStack *num;
sStack *sym;
int ans = 0;
map<char, int> level;

// void InitStack(Stack *top)
// {
//     top = (Stack *)malloc(sizeof(Stack));
//     top->next = NULL;
//     return;
// }

void Push_num(nStack *num, int sum)
{   
    nStack *p = (nStack *)malloc(sizeof(nStack));
    p->data = sum;
    p->next = num->next;
    num->next = p;
    return;
}
char GetTop(sStack *sym)
{
    if (sym->next == NULL)
        return '?';
    else
        return sym->next->data;
}

void Push_sym(sStack *sym, char c)
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
int Pop_num()
{
    if (num->next != NULL)
    {
        int x = num->next->data;
        nStack *p = num->next;
        num->next = p->next;
        free(p);
        return x;
    }
    return 0;
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
        int sum = 0;
        while (isdigit(s[count]))
        {
            sum = sum * 10 + s[count] - '0';
            count++;
        }
        if(sum!=0)
        Push_num(num,sum);
        // printf("%d\n",sum);
        if (!isdigit(s[count]))
        {   
            char c = GetTop(sym);
           
            if (c == '?'||c=='(')
            {
                Push_sym(sym, s[count]);
                count++;
            }

            else if (s[count]==')')
            {     char c = GetTop(sym);
                  while(c!='(')
                { 
                  int x = Pop_num();
                 int y=Pop_num();
                 
                int data = 0;
                switch (c)
                {
                case '+':
                    data = x + y;
                   
                    break;
                case '-':
                    data = y-x;
                    break;
                case '*':
                    data = x *y;
                    break;
                case '/':
                    data = y / x;
                    break;
                }
                Pop_sym();
                 
                Push_num(num, data);
        
                  c = GetTop(sym);
                }
                 Pop_sym();
                 count++;

            }
            else if (level[c] == level[s[count]] && (c == '#'))
            {   
                break;
            }
             else if (level[c] > level[s[count]])
            {    if(c=='(')
                  {
                    Push_sym(sym, s[count]);
                    count++;
                    continue;
                  }
                 char c = GetTop(sym);
                 int x = Pop_num();
                 int y=Pop_num();
                 
                int data = 0;
                switch (c)
                {
                case '+':
                    data = x + y;
                   
                    break;
                case '-':
                    data = y -x;
                    break;
                case '*':
                    data = x *y;
                    break;
                case '/':
                    data = y / x;
                    break;
                }
                Pop_sym();
                 
                Push_num(num, data);
            }
            else
            {    
                Push_sym(sym, s[count]);
                count++;
            }
            
        }
        //if (count >= len + 1)
           // break;
     }
    // if (num->next->next)
    // {
    //     printf("输入非法！");
    // }
    // else
    // {
         cout << num->next->data << endl;
    // }
}
int main()
{
    level['#'] = 0;
    level['+'] = 1;
    level['-'] = 1;
    level['*'] = 2;
    level['/'] = 2;
    level['('] = 3;
    level[')'] = 3;
    // InitStack(num);
    // InitStack(sym);
    sym = (sStack *)malloc(sizeof(sStack));
    sym->next = NULL;
    num = (nStack *)malloc(sizeof(nStack));
    num->next = NULL;
    sStack *p = (sStack *)malloc(sizeof(sStack));
    p->data = '#';
    p->next = sym->next;
    sym->next = p;
    Get_detail();
}