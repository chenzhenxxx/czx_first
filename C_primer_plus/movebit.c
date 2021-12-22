#include <stdio.h>
main()
{
    int x;
    printf("please input a number :\n");
    scanf("%d",&x);
    int bit;
    printf("the bit you want to move:\n");
    scanf("%d",&bit);

    int tmp;
    tmp=x<<(sizeof(int)*4-bit);
    x=x>>bit;
    x=x|tmp;
    printf("%d",x);
}