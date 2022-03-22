#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct stacknode
{
    int data;
    struct stacknode * next;
}stacknode,*stackptr;

typedef struct 
{
    stackptr top;
    int count;
}linkstack;

int push(linkstack *s,int e)
{
    stackptr p=(stacknode *)malloc(sizeof(stacknode));
    p->data=e;
    p->next=s->top;
    s->top=p;
    s->count++;
    return 1;

}



bool initstack(linkstack *s)
{
   s->top=(stackptr)malloc(sizeof(stacknode));
   if(!s->top)
    return false;
    s->top=NULL;
    s->count=0;
    return 1;

}

void clearstack(linkstack *s)
{   stackptr p,q;
    p=s->top;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
    s->top=NULL;
    s->count=0;
}
int  stackempty(linkstack  s)
{
   if(s.count==0)
    return 1;
    else
    return 0;
}

int stacklength(linkstack s)
{
   return s.count;
}
int gettop(linkstack *s,int *e)
{  
    if(s->top==NULL)
    return 0;
    else 
    *e=s->top->data;
    return 1;

}
int showstack(linkstack s)
{
    stackptr p;
    p=s.top;
    while(p)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    return 1;

}
int pop(linkstack*s,int *e)
{
    stackptr p;
    if(!stackempty(*s))
    {
        *e=s->top->data;
        p=s->top;
        s->top=p->next;
        free(p);
        s->count--;
        return 1;
    }
}
int main()
{
        int j;
        linkstack s;
        int e;
        if(initstack(&s))
                for(j=1;j<=10;j++)
                        push(&s,j);
        printf("栈中元素依次为：");
        showstack(s);
        pop(&s,&e);
        printf("弹出的栈顶元素 e=%d\n",e);
        printf("栈空否：%d(1:空 0:否)\n",stackempty(s));
        gettop(&s,&e);
        printf("栈顶元素 e=%d 栈的长度为%d\n",e,stacklength(s));
        clearstack(&s);
        printf("清空栈后，栈空否：%d(1:空 0:否)\n",stackempty(s));
        return 0;
}