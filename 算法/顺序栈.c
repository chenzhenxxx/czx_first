#include<stdio.h>
#include<stdbool.h>
#define MAXSIZE 5
typedef struct 
{
    int num[MAXSIZE];
    int top;
}sqstack;

bool initstack(sqstack *s);
void destorystack(sqstack *s);
void clearstack(sqstack *s);
bool gettop(sqstack s,int *e);
bool push(sqstack *s,int e);
bool pop(sqstack *s,int *e);
int stacklength(sqstack s);
int showstack(sqstack s);
bool stackempty(sqstack s);

int main()
{
     
        int j;
        sqstack s;
        int e;
        if(initstack(&s))
                for(j=1;j<=10;j++)
                        push(&s,j);
        printf("栈中元素依次为：");
        showstack(s);
        pop(&s,&e);
        printf("弹出的栈顶元素 e=%d\n",e);
        printf("栈空否：%d(1:空 0:否)\n",stackempty(s));
        gettop(s,&e);
        printf("栈顶元素 e=%d 栈的长度为%d\n",e,stacklength(s));
        clearstack(&s);
        printf("清空栈后，栈空否：%d(1:空 0:否)\n",stackempty(s));
        
        return 0;
}
int showstack(sqstack s)
{
    int m=s.top;
    int i=m;
    for(i;i>=0;i--)
    {
        printf("%d\n",s.num[i]);
    }
}
bool initstack(sqstack *s)
{
    s->top=-1;
    return 1;

}
void destorystack(sqstack *s)
{
    if(s->top==-1)
    return;
    s->top--;
    

}
void clearstack(sqstack *s)
{
    if(s->top==-1)
    return;
    s->top--;
}
bool stackempty(sqstack  s)
{
   if(s.top==-1)
    return true;
    else
    return false;
}
bool gettop(sqstack s,int *e)
{
    if(s.top==-1)
    return false;
    else
    *e=s.num[s.top];
    return true;
}
bool push (sqstack* s,int e)
{
    if(s->top==MAXSIZE-1)  //栈满
    return false;
    else
    {
        s->top++;
        s->num[s->top]=e;
        return true;
    }

}
bool pop (sqstack *s,int *e)
{
    if(s->top==-1)
    return false;
    *e=s->num[s->top];
    s->top--;
    return true;

}
int stacklength(sqstack s)
{
   return s.top+1;
}
