#include<stdio.h>
typedef struct Node
{
    int data;
    struct Node*next;
}node,*linklist;

linklist init (void);
void print(linklist head);
void creatbyrear(linklist head);
linklist merge(linklist head1,linklist head2);

main()
{
    node*head1,*head2;
    head1=init();
    head2=init();
    creatbyrear(head1);
    creatbyrear(head2);
    print(merge(head1,head2));
   


}
linklist init(void)
{
    node* head;
    head=(linklist)malloc(sizeof(node));
    head->next=NULL;
    return head;
}
void creatbyrear(linklist head)
{   int data;
    node*p,*tmp;
    tmp=head;
    scanf("%d",&data);
    while(data!=-1)
    {  p=(linklist)malloc(sizeof(node));
       p->data=data;
       tmp->next=p;
       tmp=p;
       scanf("%d",&data);

    }
}
void print(linklist head)
{
    int i;
    node*p;
    p=head->next;
    while(p)
    {
        printf("--%d",p->data);
        p=p->next;
    }
}
linklist merge (linklist head1,linklist head2)
{
    node*pc,*p,*q,*LC;
    LC=(linklist)malloc(sizeof(node));
    p=head1->next;
    q=head2->next;
    LC=head1;
    pc=LC;
    while(p&&q)
    {
        if(p->data>=q->data)
        { pc->next=q;
          pc=q;
          q=q->next;
       }
        else
        {   pc->next=p;
            pc=p;
            p=p->next;
        }

    }

    if(p) pc->next=p;
    if(q) pc->next=q;
    free(head2);
    return LC;
}