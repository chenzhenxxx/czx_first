#include <stdio.h>
main()
{
    int n,i;
    int p[100000];
    int a[100000];
    scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         scanf("%d",&p[i]);
         int count=0;
         while(p[i])
         {
             if(p[i]%2!=0)
             count++;
             p[i]/=2;

         }
         a[i]=count;

     }
     for(i=0;i<n;i++)
     {
         printf("%d\n",a[i]);
     }


}