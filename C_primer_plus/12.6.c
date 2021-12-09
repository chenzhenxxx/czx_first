#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main()
{    int a[11]={0};
int i,j;
     for(i=0;i<10;i++)
     {
         srand((unsigned int)time(0));
         for(j=0;j<100;j++)
         {
             a[rand()%10+1]++;
         }
     }
     for(i=1;i<=10;i++)
     printf("%d: %d ",i,a[i]);
     
}
