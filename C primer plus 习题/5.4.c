#include <stdio.h>
main()
{  float height,cun;
int chi;
   printf("please input a hight:\n");
   scanf("%f",&height);
   chi=height/30.48;
   cun=(height-chi*30.48)/2.54;
   printf("%.1f cm = %d feet, %.1f inches\n168.7",height,chi,cun);
   do{
   scanf("%f",&height);
   chi=height/30.48;
   cun=(height-chi*30.48)/2.54;
   printf("%.1f cm = %d feet, %.1f inches(<=0 to quit)\n",height,chi,cun);
}while(height>0);
printf("bye");
}
