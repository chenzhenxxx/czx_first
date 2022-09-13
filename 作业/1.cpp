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
    for (int i = 2; i <= 20; i++)
    {
        List *p = (List *)malloc(sizeof(List));
        p->data = i;
        p->next = NULL;
        tmp->next = p;
        tmp = p;
    }
    tmp->next = NULL;
}

void Delete_insert(List *A, int i, int len, List *B, int j)
{
    List *it = B, *wb = A;
    List *begin = A;
    j = j - 1;
    while (j--)
    {
        it = it->next;
    }
    while (wb->next)
    {
        wb = wb->next;
    }
    List *tmp_b = it->next;

    if (i == 1)
    {
        while (len--)
        {
            List *tmp = A;
            A = A->next;
            free(tmp);
        }
        it->next = A;
        wb->next = tmp_b;
    }
    else
    {
        List *tmp = begin;
        List *first;
        i = i - 1;
        while (i--)
        {
            first = begin;
            begin = begin->next;
        }
        tmp = begin;
        while (len--)
        {
            List *clean = tmp;
            tmp = tmp->next;
            free(clean);
        }
        first->next = tmp;
        it->next = A;
        wb->next = tmp_b;
    }
}
void Print(List *L)
{

    List *lnode = L;
    while (lnode)
    {
        printf("%d ", lnode->data);
        lnode = lnode->next;
    }
    printf("\n");
}

int List_len(List *A)
{
   int i=0;
   List *lnode=A;
   while(lnode)
   {
     i++;
     lnode=lnode->next;
   }
   return i;
}



int main()
{
    int i, len, j;
    int len_a, len_b;
    List *A;
    List *B;
    A = (List *)malloc(sizeof(List));
    A->data = 1;
    A->next = NULL;
    B = (List *)malloc(sizeof(List));
    B->data = 1;
    B->next = NULL;
    Init_List(A);
    Init_List(B);
    len_a = List_len(A);
    len_b = List_len(B);
    printf("请输入要A删除的起始位置\n");
    scanf("%d", &i);
    if (i > len_a)
    {
        cout << "起始位置超出链表长度！" << endl;
        return 0;
    }
    printf("请输入要A删除的长度\n");
    scanf("%d", &len);
    if (i + len > len_b)
    {
        cout << "链表越界！" << endl;
        return 0;
    }
    printf("请输入要B插入的起始位置\n");
    scanf("%d", &j);
    if (j > len_b)
    {
        cout << "起始位置超出链表长度！" << endl;
        return 0;
    }

    Print(B);
    Delete_insert(A, i, len, B, j);
    Print(B);
}
