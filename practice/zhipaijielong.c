#include <stdio.h>
struct queue
{
    int a[1000];
    int head;
    int tail;
};
struct stack
{
    int data[10];
    int top;
};
main()
{
    struct queue q1,q2;
    struct stack s;
    int i,n,t;
    int book[10];
    q1.head=1;
    q2.head=1;
    s.top=0;
    for(i=1;i<=9;i++)
    book[i]=0;
    printf("the pai you own\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&q1.a[i]);
    for(i=1;i<=n;i++)
     scanf("%d",&q2.a[i]);
     q1.tail=n+1;
     q2.tail=n+1;
     
     while(q1.head<q1.tail&&q2.head<q2.tail)
     {   
         t=q1.a[q1.head];
         if(book[t]==0)
     {   
         s.top++;
         s.data[s.top]=t;
         q1.head++;
         book[t]=1;
     }
     else
     {   q1.head++;
         q1.a[q1.tail]=t;
         q1.tail++;
         while(s.data[s.top]!=t)
         { book[s.data[s.top]]=0;
             q1.a[q1.tail]=s.data[s.top];
             s.top--;
             q1.tail++;
         }
     
     book[t]=0;
      q1.a[q1.tail]=t;
      q1.tail++;
      s.top--;
     }
    if(q1.head==q1.tail)
    break;
     


         t=q2.a[q2.head];
         if(book[t]==0)
     {   s.top++;
         s.data[s.top]=t;
          book[t]=1;
         q2.head++;
     }
     else
     {   q2.head++;
         q2.a[q2.tail]=t;
         q2.tail++;
         while(s.data[s.top]!=t)
         {   book[s.data[s.top]]=0;
             q2.a[q2.tail]=s.data[s.top];
             q2.tail++;
             s.top--;
         }
         book[t]=0;
         q2.a[q2.tail]=t;
         q2.tail++;
         s.top--;


     }
     }
   

     if(q1.head==q1.tail)
     {
         printf("q2 win \n");
         printf("the q2 have the pai :\n");
         for(i=q2.head;i<q2.tail;i++)
         printf("%d",q2.a[i]);
         if(s.top!=0)
        { printf("the table have pai:\n");
         for(i=1;i<=s.top;i++)
         printf("%d ",s.data[i]);
        }

     }

      if(q2.head==q2.tail)
     {
         printf("q1 win \n");
         printf("the q1 have the pai :\n");
         for(i=q1.head;i<q1.tail;i++)
         printf("%d",q1.a[i]);
         if(s.top!=0)
        { printf("the table have pai:\n");
         for(i=1;i<=s.top;i++)
         printf("%d ",s.data[i]);
        }

     }
 

}
