#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct LList
{
   int data;
   struct LList *next;
} List, *LinkList;
void InitList(List *h)
{
   h = (struct LList *)malloc(sizeof(struct LList));
   h->next = NULL;
}
void Print(List *head)
{
   List *p = head->next;
   while (p)
   {
      printf("%d ", p->data);
      p = p->next;
   }
   printf("\n");
}

void ReverseList(List * &head)
{
   List *begin, *mid, *end;
   begin = NULL;
   mid = head->next;
   end = mid->next;
   while (end)
   {
      mid->next = begin;
      begin = mid;
      mid = end;
      end = end->next;
   }
   mid->next = begin;
   head->next= mid;

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
      tmp->next = NULL;
      Print(head);
      ReverseList(head);
      Print(head);
      List *p = head->next;
      while (p)
      {
         List *q = p->next;
         free(p);
         p = q;
      }
      free(head);
   }