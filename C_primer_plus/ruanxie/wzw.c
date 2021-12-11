#include <stdio.h>
typedef struct Subject
{
    char a[100];
    int time;
}suject;
suject s[100];
suject t,k;
void quicksort(int left,int right);
main()
{  
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s %d",s[i].a,&s[i].time);
    }
   quicksort(0,n-1);
    for(i=0;i<n;i++)
    printf("%s",s[i].a);
}
void quicksort(int left,int right)
{  int i,j,tmp;
   tmp=s[left].time;
   k=s[left];
   i=left;
   j=right;
   if(left>right)
   return ;
   while(i!=j)
   {
       while(s[j].time>=tmp&&j>i)
       j--;
       while(s[i].time<=tmp&&j>i)
       i++;
       if(j>i)
       {t=s[i];
       s[i]=s[j];
       s[j]=t;

       }
   }
   s[left]=s[i];
   s[i]=k;
   quicksort(left,i-1);
   quicksort(i+1,right);
    
}