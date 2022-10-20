#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Stack{
    char data[512];
    int top;
}Stack;
void Push(Stack *stack,char c)
{    stack->top++;
     stack->data[(stack->top)]=c;
     
}
char Pop(Stack * stack)
{   
    char c=stack->data[(stack->top)];
    stack->top--;
    return c;
}
int Empty(Stack stack)
{
    if(stack.top==-1)
    return 1;
    else 
    return 0;
}
void Diverse(Stack *stack,char *to)
{   int cnt=0;
    while(!Empty(*stack))
    {   
       to[cnt]=Pop(stack);
       cnt+=1;
    }
    to[cnt]='\0';
    
}
int main(){
   char tmp[512];
   int len=0;
   printf("please input string: ");
   scanf("%s",&tmp);

   len=strlen(tmp);
   Stack stack;
   stack.top=-1;
   for(int i=0;i<len;i++)
   {
    Push(&stack,tmp[i]);
   }
   char cmp[len+1];
   Diverse(&stack,cmp);
   printf("%s",cmp);
   if(strcmp(cmp,tmp)==0)
   {
    printf("yes!\n");
   }
   else
   printf("no!\n");
}