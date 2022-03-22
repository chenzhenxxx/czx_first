#include<stdio.h>
#include<stdlib.h>
typedef struct qnode
{
   int data;
   struct qnode *next;
}qnode,*qnodeptr;

typedef struct 
{
    qnodeptr front,rear;
}linknode;

int initqueue(linknode *q)
{
    q->front=q->rear=(qnodeptr)malloc(sizeof(qnode ));
    if(!q->front)
    exit(0);
    q->front->next=NULL;
    return 1;
}
int enqueue(linknode *q,int e)
{
    qnodeptr p;
    p=(qnodeptr)malloc(sizeof(qnode));
    if(!p)
    return 0;
    p->data=e;
    q->rear->next=p;
    q->rear=p;
    return 1;
}
int destroyqueue (linknode *q)
{
    while(q->front)
    {
        q->rear=q->front->next;
        free(q->front);
        q->front=q->rear;

    }
    return 1;
}
int clearqueue(linknode *q)
{
    qnodeptr p,r;
    q->rear=q->front;
    p=q->front->next;
    q->front->next=NULL;
    while(p)
    {
        r=p;
        p=p->next;
        free(r);
    }
    return 1;

}
int queueempty(linknode q)
{
    if(q.front==q.rear)
    return 1;
    else
    return 0;
}
int queuelength(linknode q)
{
    int len=0;
    qnodeptr p;
    p=q.front;
    while(q.rear!=p)
    {
    len++;
        p=p->next;
    }
    return len;
}
int gethead(linknode q,int *e)
{
    qnodeptr p;
    if(q.front==q.rear)
    return 0;
    p=q.front->next;
    *e=p->data;
    return 1;
}
int showqueue(linknode q)
{
    qnodeptr p;
    p=q.front->next;
    while(p)
    {
        printf("%d\n",p->data);
        p=p->next;
       
    }
     return 1;
}
int dequeue(linknode *q,int *e)
{
    qnodeptr p;
    p=q->front->next;
    *e=p->data;
    q->front->next=p->next;
     if(q->rear==p)
     q->rear=q->front;
    free(p);
    return 1;
}
int main()
{
   int i;
	int d;
	linknode q;
	i=initqueue(&q);
	if(i)
		printf("成功地构造了一个空队列!\n");
	printf("是否空队列？%d(1:空 0:否)  ",queueempty(q));
	printf("队列的长度为%d\n",queuelength(q));
	enqueue(&q,-5);
	enqueue(&q,5);
	enqueue(&q,10);
	printf("插入3个元素(-5,5,10)后,队列的长度为%d\n",queuelength(q));
	printf("是否空队列？%d(1:空 0:否)  ",queueempty(q));
	printf("队列的元素依次为：");
	showqueue (q);
	i=gethead(q,&d);
	if(i==1)
	 printf("队头元素是：%d\n",d);
	dequeue(&q,&d);
	printf("删除了队头元素%d\n",d);
	i=gethead(q,&d);
	if(i==1)
		printf("新的队头元素是：%d\n",d);
	clearqueue(&q);
	printf("清空队列后,q.front=%u q.rear=%u q.front->next=%u\n",q.front,q.rear,q.front->next);
	destroyqueue(&q);
	printf("销毁队列后,q.front=%u q.rear=%u\n",q.front, q.rear);
	
	return 0;
}