#include <stdio.h>
main()
{   int i,n;
    float p=1,sum1=0,sum2=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum1+=1.0/i;
        sum2+=p/i;
        p=-1*p;
    }
    printf("%f %f",sum1,sum2);
}