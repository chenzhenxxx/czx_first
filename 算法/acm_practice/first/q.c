#include <stdio.h>
#include <stdlib.h>

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