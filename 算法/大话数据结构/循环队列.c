#include<stdio.h>
#define MAXSIZE 20
typedef struct
{
    int front;
    int rear;
    int data[MAXSIZE];
} queue;
int initqueue(queue* q)
{
    q->front=0;
    q->rear=0;
    return 1;
}
int push(queue*q,int e)
{
    if((q->rear+1)%MAXSIZE==q->front)
    return 0;
    q->data[q->rear]=e;
    q->rear=(q->rear+1)%MAXSIZE;
    return 1;
}
int pop (queue*q,int *e)
{
    if(q->rear==q->front)
    return 0;

    *e=q->data[q->front];
    q->front=(q->front+1)%MAXSIZE;
    return 1;
}
int queuelength(queue q)
{
    return (q.rear-q.front+MAXSIZE)%MAXSIZE;
}
int showqueue(queue q)
{
    int i;
    for(i=q.front;i<=q.rear;i++)
    printf("%d\n",q.data[i]);
    return 1;

}
int clearqueue(queue q)
{
    q.rear=q.front=0;
    return 1;
}
int queueempty(queue q)
{
    if(q.front==q.rear)
    return 0;
    else
    return 1;
}
int gethead(queue q,int *e)
{
    if(q.front==q.rear)
     return 0;
     *e=q.data[q.front];
     return 1;
}
int main()
{
    int j;
	int i=0,l;
	int d;
	queue Q;
	initqueue(&Q);
	printf("初始化队列后，队列空否？%u(1:空 0:否)\n",queueempty(Q));

	printf("请输入整型队列元素(不超过%d个),-1为提前结束符: ",MAXSIZE-1);
	do
	{
		/* scanf("%d",&d); */
		d=i+100;
		if(d==-1)
			break;
		i++;
		push(&Q,d);
	}while(i<MAXSIZE-1);

	printf("队列长度为: %d\n",queuelength(Q));
	printf("现在队列空否？%u(1:空 0:否)\n",queueempty(Q));
	printf("连续%d次由队头删除元素,队尾插入元素:\n",MAXSIZE);
	for(l=1;l<=MAXSIZE;l++)
	{
		pop(&Q,&d);
		printf("删除的元素是%d,插入的元素:%d \n",d,l+1000);
		/* scanf("%d",&d); */
		d=l+1000;
		push(&Q,d);
	}
	l=queuelength(Q);

	printf("现在队列中的元素为: \n");
	showqueue(Q);
	printf("共向队尾插入了%d个元素\n",i+MAXSIZE);
	if(l-2>0)
		printf("现在由队头删除%d个元素:\n",l-2);
	while(queuelength(Q)>2)
	{
	pop(&Q,&d);
		printf("删除的元素值为%d\n",d);
	}

	j=gethead(Q,&d);
	if(j)
		printf("现在队头元素为: %d\n",d);
	clearqueue(Q);
	printf("清空队列后, 队列空否？%u(1:空 0:否)\n",queueempty(Q));
	return 0;
}