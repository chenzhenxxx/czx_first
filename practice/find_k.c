#include <stdio.h>

int a[500005],k;
 void quicksort(begin,end)
 {
     
     int tmp=a[(begin+end)/2];
     int i,j;
     i=begin;
     j=end;
     while(i<=j)
     {
         while(a[j]>tmp)
         j--;
         while(a[i]<tmp)
         i++;
         if(i<=j)
         {
             int t;
             t=a[i];
             a[i]=a[j];
             a[j]=t;
             i++;
             j--;
         }
     }
     
    if(k<=j) quicksort(begin,j);
	else if(i<=k) quicksort(i,end);
	else 
	{
		printf("%d",a[j+1]);
		exit(0);
	}

 }
main()
{
    int n,i;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    quicksort(0,n-1);
   

}