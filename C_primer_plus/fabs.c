#include<stdio.h>
main()
{
    int x;
    scanf("%d",&x);
    if(x>0)
    printf("%d",x);
    else
    printf("the number fabs is %d",~x+1);
}