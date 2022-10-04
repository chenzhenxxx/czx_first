#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef struct LList
{
    int data;
    struct LList *next;
    struct LList* prior;
} List, *LinkList;
List *near;

void Create_List(List *head, int people)
{
    List *tmp = head;
    for (int i = 2; i <= people; i++)
    {
        List *p = (List *)malloc(sizeof(List));
        p->data = i;
        p->next = NULL;
        tmp->next = p;
        p->prior=tmp;
        tmp = p;
    }
    tmp->next = head;
    head->prior=tmp;
}

void Find_x_s(List *head, int n, int k)
{
    List *p = head;
    List *tmp = head;
    while (tmp->next != head) //找到尾节点
    {
        tmp = tmp->next;
    }
    while (p->data != n)
    {
        tmp = p; //假如数1
        p = p->next;
    }
    while (p->next != p) //只剩她一个
    {
        for (int i = 1; i < k; i++)
        {
            tmp = p;
            p = p->next;
        }
        tmp->next = p->next;
        p->next->prior=tmp;
        printf("%d出局\n", p->data);
        free(p);
        p = tmp->next;
    }
    printf("winner的编号为:%d\n", p->data);
    free(p);
}

void Find_x_n(List *head, int n, int k)
{
    List *p = head;
    List *tmp = head->next;
    //while (tmp->next != head) //找到尾节点
   //{
      //  tmp = tmp->next;
   // }
    while (p->data != n)
    {
        tmp = p; //假如数1
        p = p->prior;
    }
    while (p->prior != p) //只剩她一个
    {
        for (int i = 1; i < k; i++)
        {
            tmp = p;
            p = p->prior;
        }
        tmp->prior = p->prior;
        p->prior->next=tmp;
        printf("%d出局\n", p->data);
        free(p);
        p = tmp->prior;
    }
    printf("winner的编号为:%d\n", p->data);
    free(p);
}
int main()
{
    int people, n, k,select=-15;
    List *head;
    head = (struct LList *)malloc(sizeof(struct LList));
    head->next = NULL;
    head->data = 1;
    printf("请输入桌子上的人数\n");
    cin >> people;
    if(people<0)
    {
        printf("人数负数非法！\n");
        return 0;
    }
    printf("请输入从第几个人开始\n");
    cin >> n;
    if(n>people)
    {
        cout<<"输入错误"<<endl;
        return 0;
    }
    printf("请输入数到多少出列\n");
    cin >> k;
    if(k<0)
    {
        printf("数字负数非法!\n");
        return 0;
    }
    Create_List(head, people);
    printf("请选择顺时针/逆时针(0/1)\n");
    cin>>select;
    if(select==0)
    Find_x_s(head, n, k);
    else if(select==1)
    Find_x_n(head, n, k);
    else
    {
        printf("请输入正确的选择!\n");
        return 0;
    }

}