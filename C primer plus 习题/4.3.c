#include <stdio.h>
#include <string.h>
main()
{  
   float a;
   scanf("%f",&a);
   printf("The input is %.1f or %.1e\n",a,a);
   printf("The input is %+.3f or %.3E",a,a);

}