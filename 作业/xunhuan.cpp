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

void Print(List *head)
{
   List *p = head->next;
   while (p!=head)
   {
      printf("%d ", p->data);
      p = p->next;
   }
   printf("\n");
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
    tmp->next = head;
    Print(head);
    List *p = head->next;
    while (p!=near)
    {
        List *q = p->next;
        free(p);
        p = q;
    }
    free(head);
    
}