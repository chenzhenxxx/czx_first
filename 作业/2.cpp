#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct LList
{
    int data;
    struct LList *next;
} List, *LinkList;

void Init_List(List *head)
{
    List *tmp = head;
    printf("请输入链表长度！\n");
    int len = 0;
    cin >> len;
    while (len--)
    {
        int data;

        List *p = (List *)malloc(sizeof(List));
        printf("请输入数据:\n");
        cin >> data;
        p->data = data;
        tmp->next = p;
        tmp = p;
    }
    tmp->next = NULL;
}

int List_len(List *A)
{
    int i = 0;
    List *lnode = A->next;
    while (lnode)
    {
        i++;
        lnode = lnode->next;
    }
    return i;
}

List *Merge(List *A, List *B)
{
    List *C;
    List *a = A->next;
    List *b = B->next;
    C = (List *)malloc(sizeof(List));
    List *c = C;
    int cnt = 0;
    while (a && b)
    {
        if (cnt % 2 == 0)
        {
            cnt++;
            c->next = a;
            c = a;
            a = a->next;
        }
        else
        {
            cnt++;
            c->next = b;
            c = b;
            b = b->next;
        }
    }
    c->next=b;
    return C;
}

void Print(List *L)
{

    List *lnode = L->next;
    while (lnode)
    {
        printf("%d ", lnode->data);
        lnode = lnode->next;
    }
    printf("\n");
}
int main()
{
    int i, len, j;
    int len_a, len_b;
    List *A;
    List *B;
    List *C;
    A = (List *)malloc(sizeof(List));
    B = (List *)malloc(sizeof(List));
    A->next = NULL;
    B->next = NULL;
    Init_List(A);
    Init_List(B);
    len_a = List_len(A);
    len_b = List_len(B);
    cout << len_a << " " << len_b<<endl;
    if (len_a > len_b)
    {
        C = Merge(B, A);
    }
    else
    {
        C = Merge(A, B);
    }
    Print(C);
}
