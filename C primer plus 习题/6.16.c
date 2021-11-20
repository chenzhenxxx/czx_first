#include <stdio.h>
main()
{ int i;
  float n=100,m=100,h;
  h=n;
  for(i=1;;i++)
  {n=n+0.1*h;
   m=m*1.05;
   if(n<=m)
   {
     printf("need %d de have %f and da have %f",i,n,m);
     break;
   }
    
  }
}