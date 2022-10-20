#include <stdio.h>
#include <stdlib.h>
typedef struct Qnode
{
    int data;
    struct Qnode *next;
} Qnode, *Linkqnode;

typedef struct Linkqueue
{
    Linkqnode rear;
} Linkqueue;

void Init(Linkqueue *queue)
{
    queue->rear = (Qnode *)malloc(sizeof(Qnode));
    queue->rear->next = queue->rear;
}

void EnterQueue(Linkqueue *queue,int a)
{
    Qnode *p=(Qnode *)malloc(sizeof(Qnode));
    p->data=a;
    p->next=queue->rear->next;
    queue->rear->next=p;
    queue=p;
}
void DeleteQueue(Linkqueue *queue,int *a)
{
    Qnode *q=queue->rear->next;
    *a=q->data;
    queue->rear->next->next=q->next;
    if(queue->rear->next->next == queue->rear->next)
    queue->rear=queue->rear->next;
    free(q);
    



}
int Empty(Linkqueue q)
{
    if(q.rear==q.rear->next)
    return 1;
    else
    return 0;
}
int main()
{   int tmp=0;
    Linkqueue queue;
    Init(&queue);
     printf("empty(1:yes,0:no):%d\n",Empty(queue));
     EnterQueue(&queue,1);
      printf("empty(1:yes,0:no):%d\n",Empty(queue));
     EnterQueue(&queue,2);
     DeleteQueue(&queue,&tmp);
     printf("delete :%d\n",tmp);
}