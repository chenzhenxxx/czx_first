#include <iostream>
#include <cmath>
using namespace std;
typedef struct node
{
    int x;
    int z;
    struct node *next;
} List;
void update(List *head)
{
    List *p = head;
    while (p->next)
    {
        if (p->next->x == 0)
        {
            p->next = p->next->next;
            continue;
        }
        p = p->next;
    }
}
void Insert(int n, int m, List *head)
{
    List *tmp = (List *)malloc(sizeof(List));
    tmp->x = n;
    tmp->z = m;
    tmp->next = NULL;
    List *q = head;
    while (q->next)
    {
        if (q->next->z == tmp->z)
        {
            q->next->x += tmp->x;
            return;
        }
        if (q->next->z > tmp->z)
            break;

        q = q->next;
    }

    if (!q->next)
    {
        q->next = tmp;
        return;
    }
    tmp->next = q->next;
    q->next = tmp;
}
void Create(List *head)
{
    int n, m;
    printf("请输入系数 指数(输入0 0结束)\n");
    while (scanf("%d %d", &n, &m) && !(n == 0 && m == 0))
    {
        Insert(n, m, head);
    }
}
void Print(List *A)
{
    List *a = A->next;
    if (!a)
    {
        printf("0");
        return;
    }
    while (a)
    {   
        if(a!=A->next&&a->x>0)
        {
            printf("+");
        }
        printf("%dx%d", a->x, a->z);
        a = a->next;
    }
}
List *Add(List *A, List *B)
{
    List *C;
    C = (List *)malloc(sizeof(List));
    C->next = NULL;
    List *tmp = A->next;
    while (tmp)
    {
        Insert(tmp->x, tmp->z, C);
        tmp = tmp->next;
    }
    tmp = B->next;
    while (tmp)
    {
        Insert(tmp->x, tmp->z, C);
        tmp = tmp->next;
    }

    return C;
}
List *sub(List *A, List *B)
{
    List *C;
    C = (List *)malloc(sizeof(List));
    C->next = NULL;
    List *tmp = A->next;
    while (tmp)
    {
        Insert(tmp->x, tmp->z, C);
        tmp = tmp->next;
    }
    tmp = B->next;
    while (tmp)
    {
        Insert(-tmp->x, tmp->z, C);
        tmp = tmp->next;
    }

    return C;
}

List *Mul(List *A, List *B)
{
    List *C = (List *)malloc(sizeof(List));
    List *p = A->next;
    List *q = B->next;
    if (!p) // p是空
    {
        //while (q)
       // {
            Insert(0, 0, C);
            //q = q->next;
        //}
        
        return C;
    }
    if (!q)
    {
       // while (p)
        //{
            Insert(0, 0, C);
            //p = p->next;
        //}
        return C;
    }

    while (p)
    {
        List *tmp = q;
        while (tmp)
        {
            Insert(p->x * tmp->x, p->z + tmp->z, C);
            tmp = tmp->next;
        }
        p = p->next;
    }
    return C;
}

int answer(List *A, int x)
{
    int ans = 0;
    List *a = A->next;
    while (a)
    {
        ans += a->x * pow(x, a->z);
        a = a->next;
    }
    return ans;
}

List *Derivative(List *A)
{
    List *C = (List *)malloc(sizeof(List));
    List *tmp = A->next;
    while (tmp)
    {
        Insert(tmp->x * tmp->z, tmp->z - 1, C);
        tmp = tmp->next;
    }
    return C;
}
int main()
{
    int x;
    List *C;
    C = (List *)malloc(sizeof(List));
    C->next = NULL;
    List *A;
    A = (List *)malloc(sizeof(List));
    List *B;
    B = (List *)malloc(sizeof(List));
    A->next = NULL;
    B->next = NULL;
    printf("请输入多项式A\n");
    Create(A);
    update(A);
    cout<<"this is A :"<<endl;
    Print(A);
    cout << endl;

    C = Derivative(A);
    update(C);
    printf("A derivative:");
    Print(C);
    cout << endl;

    printf("请输入多项式B\n");
    Create(B);
    update(B);
    cout<<"this is B :"<<endl;
    Print(B);
    cout << endl;
    C = Derivative(B);
    update(C);
    printf("B derivative:");
    Print(C);
    cout << endl;

    C = Add(A, B);
    update(C);
    cout << "this is add:" << endl;
    Print(C);
    cout << endl;
    cout << "this is sub:" << endl;
    C = sub(A, B);
    update(C);
    Print(C);
    cout << endl;
    cout << "this is mul:" << endl;
    C = Mul(A, B);
    update(C);
    Print(C);
    cout << endl;

    cout << "秦输入x值以求值" << endl;
    cin >> x;
    int ans_a = answer(A, x);
    int ans_b = answer(B, x);
    printf("在值%d下A的值为：%d\n", x, ans_a);
    printf("在值%d下B的值为%d\n", x, ans_b);
}