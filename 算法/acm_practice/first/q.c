#include <stdio.h>
#include <stdlib.h>

void quicksort(int *a,int begin,int end)
{
    int i=begin;
    int j=end;
    int tmp=a[begin];
    if(end<begin)
    return;
    while(i<j)
    {
        while(a[j]>=tmp&&i<j)
        j--;
        while(a[i]<=tmp&&i<j)
        i++;
        if(i<j)
        {
            int t;
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    a[begin]=a[i];
    a[i]=tmp;
    quicksort(a,i+1,end);
    quicksort(a,begin,i-1);
}
main()
{
   int n,j;
   scanf("%d",&n);
   int a[n+1];
   int i;
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   
   quicksort(a,0,n-1);

   int m=n/2;
   int count=n;
   for(int j=0;j<n/2;j++)
   {
       while(a[j]*2>a[m]&&m<n)
        m++;
        if(m>=n)
        break;

        m++;
        count--;

         
   }

   printf("%d",count);
}