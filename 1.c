 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 main()
 { int i,j,t;
   int a[101];
   for(i=0;i<100;i++)
   a[i]= rand()%10+1;
   for(i=0;i<100;i++)
   for(j=i+1;j<100;j++)
   if(a[i]<a[j])
   {
     t=a[i];
     a[i]=a[j];
     a[j]=t;
   }
   for(i=0;i<100;i++)
   printf("%d ",a[i]);

 }
