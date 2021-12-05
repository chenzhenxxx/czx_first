#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int atoi_(char *a);
main()
{
    char a[20];
    gets(a);
    printf("%d\n",atoi_(a));
    return 0;
}
int atoi_(char *a)
{   int n;
    while(*a)
    {
        n*=10;
        if(!isdigit(*a))
        return 0;
        n+=*a-'0';
        a++;
    }
        return n;

}