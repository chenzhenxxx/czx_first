//main.c
#include<stdio.h>
#include"test.h"
int main(void)
{
    printf("it will print from 5 to 1\n");
    printNum(5);
    printf("print end\n");

    printf("it will print 1 to 5\n");
    printNum1(5);
    printf("print end\n");
    return 0;
}
