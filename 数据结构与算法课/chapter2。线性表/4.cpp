#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct LList
{
    int data;
    struct LList *next;
} List, *LinkList;
List *near;
void InitList(List *h)
{
    h = (struct LList *)malloc(sizeof(struct LList));
    h->next = NULL;
}
void Delete_x(List * s)
{   List * p=s;
    List *q;
    while(p->next->next!=s)
    {
        p=p->next;
    }
    q=p->next;
    p->next=s;
    free(q);
}
int main()
{
    List *head = NULL;
    head = (struct LList *)malloc(sizeof(struct LList));
    head->next = NULL;
    printf("亲输入个数\n");
    int size;
    cin >> size;
    List *tmp = head;
    while (size--)
    {
        int num;
        cin >> num;
        List *p;
        p = (struct LList *)malloc(sizeof(struct LList));
        p->data = num;
        tmp->next = p;
        tmp = p;
    }
    near = tmp;
    tmp->next = head->next;
    Delete_x(s);
   
    List *p = head->next;
    while (size--)
    {
        List *q = p->next;
        free(p);
        p = q;
    }
    
}