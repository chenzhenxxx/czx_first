#include <stdio.h>
main()
{   int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
    long long i,j;
    scanf("%lld",&j);
    i=-(j-1);
    printf("%lld %lld\n",i,j);
    }

}