#include <stdio.h>
pow(double a,int b);
int main(int argc, char const *argv[])
{
    char *end;
    double a=strtod(argv[1],&end);
    long b=strtol(argv[1],&end,10);
    double sum=1.0;
    for(long i=0;i<b;i++)
    {
        sum*=a;
    }
    printf("%lf\n",sum);
    return 0;
}
