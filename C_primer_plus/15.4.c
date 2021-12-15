#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<limits.h>
const int size=CHAR_BIT *sizeof(int);
display(int n,int loc)
{
    int x=1;
    x<<=(loc-1);
    if(x&n)
    return 1;
    else
    return 0;
}

main()
{
    int n,loc,flag;
    scanf("%d %d",&n,&loc);
    flag=display(n,loc);
    printf("%d",flag);
    return 0;
}