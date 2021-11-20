#include <stdio.h>
main()
{  int a,sumo=0,sumj=0,o=0,j=0;
    while(scanf("%d",&a)&&a!=0)
    {
        if(a%2==0)
        {
            o++;
        sumo+=a;
        }
        else
        {
            j++;
            sumj+=a;
        }
    }
    printf("o geshu %d average %f\n",o,sumo*1.0/o);
    printf("j geshu %d average %f",j,sumj*1.0/j);

}