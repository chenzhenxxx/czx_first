#include <stdio.h>
 int h[101];
 int n;
 void swap(int i,int j)
 {
     int t;
     t=h[i];
     h[i]=h[j];
     h[j]=t;
 }
 void siftdown(int i)
 { int flag=0,t;
     while(2*i<=n&&flag==0)
     {
         if(h[2*i]>h[i])
        {
          t=2*i;
        }
         else
          t=i;
          if(i*2+1<=n)
          {
              if(h[t]<h[2*i+1])
              {
                  t=2*i+1;
              }
          }
          if(t!=i)
          {
              swap(t,i);
              i=t;
          }
          else
          flag=1;
     }

   return;
 }

 void creat()
 {
     int i;
     for(i=n/2;i>=1;i--)
     siftdown(i);
 }

 void heapsort()
 {
     while(n>1)
     {
         swap(1,n);
         n--;
         siftdown(1);
     }
 }
 
main()
{
   
    
    scanf("%d",&n);
    int i,num;
    num=n;
    for(i=1;i<=n;i++)
    scanf("%d",&h[i]);
    creat();
    heapsort();
    for(i=1;i<=num;i++)
    printf("%d ",h[i]);




}