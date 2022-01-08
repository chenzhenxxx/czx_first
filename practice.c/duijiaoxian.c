#include <stdio.h>
main()
{
    unsigned long long n;
    scanf("%llu",&n);
    printf("%llu",n*(n-1)/2*(n-2)/3*(n-3)/4);
}