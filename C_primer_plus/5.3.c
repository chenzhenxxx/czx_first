#include <stdio.h>
main()
{
    int day;
       printf("please input day:\n");
    scanf("%d",&day);
    while(day>0)
    {
    printf("%d days are %d weeks, %d days",day,day/7,day%7);
    printf("please input day:\n");
    scanf("%d",&day);
    }
}