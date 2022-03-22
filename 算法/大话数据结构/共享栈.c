#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 20
typedef struct 
{
    int data[MAXSIZE];
    int top1;
    int top2;
}sharestack;

bool push(sharestack *s,int e,int flag)
{
    if(s->top1+1==s->top2) //栈满了
    return 0;
    if(flag==1)
    {
        s->top1++;
        s->data[s->top1]=e;
    }
    else
    {
        s->top2--;
        s->data[s->top2]=e;

    }
    return 1;
}
bool pop(sharestack *s,int *e,int flag)
{
    if(flag==1)
    {
        if(s->top1==-1)
        return 0;
        *e=s->data[s->top1];
        s->top1--;
        return 1;
    }
    if(flag==2)
    {
        if(s->top2==MAXSIZE)
        return 0;
        *e=s->data[s->top2];
        s->top2++;
        return 1;
    }
}

int showstack(sharestack s)
{
    int m=s.top1;
    int n=s.top2;
    int i;
    printf("for top1:\n");
    for(i=m;i>=0;i--)
    {
        printf("%d\n",s.data[i]);
    }

    printf("for top2:\n");
    for(i=MAXSIZE-1;i>=n;i--)
    {
        printf("%d\n",s.data[i]);
    }
}
bool initstack(sharestack *s)
{
    s->top1=-1;
    s->top2=MAXSIZE;
    return 1;

}
void destorystack(sharestack *s)
{
    while(s->top1>-1)
    {
        s->top1--;
    }
    while(s->top2<MAXSIZE)
    {
         s->top2++;
    }
    

}
void clearstack(sharestack *s)
{
    while(s->top1>-1)
    {
        s->top1--;
    }
    while(s->top2<MAXSIZE)
    {
         s->top2++;
    }
    
}
bool stackempty(sharestack  s)
{
   if(s.top1==-1&&s.top2==MAXSIZE)
    return true;
    else
    return false;
}

int stacklength(sharestack s)
{
   return MAXSIZE-s.top2+s.top1+1;
}

int main()
{
       int j;
        sharestack s;
        int e;
        if(initstack(&s))
        {
                for(j=1;j<=5;j++)
                        push(&s,j,1);
                for(j=MAXSIZE;j>=MAXSIZE-2;j--)
                        push(&s,j,2);
        }

        printf("栈中元素依次为：");
        showstack(s);

        printf("当前栈中元素有：%d \n",stacklength(s));

        pop(&s,&e,2);
        printf("弹出的栈顶元素 e=%d\n",e);
        printf("栈空否：%d(1:空 0:否)\n",stackempty(s));

        for(j=6;j<=MAXSIZE-2;j++)
                push(&s,j,1);

        printf("栈中元素依次为：");
        showstack(s);

        printf("栈满否：%d(1:否 0:满)\n",push(&s,100,1));

        
        clearstack(&s);
        printf("清空栈后，栈空否：%d(1:空 0:否)\n",stackempty(s));
        
        return 0;
}