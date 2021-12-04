#define time 60;
#include <stdio.h>
main()
{
float min,hour,sec;
scanf("%f",&min);
   while(min>0)
{sec=min*time;
 hour=min/time;
    printf("sec= %.2f hour= %.2f",sec,hour);
    scanf("%f",&min);
}
}
