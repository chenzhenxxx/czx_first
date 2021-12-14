#include <stdio.h>
void transform(double*p1,double*p2,int n,double(*fun)(double));
double pf(double n);

main()
{  double a[5]={2,4,6,8,10};
   double b[5];
   transform(a,b,5,pf);

}
double pf(double n)
{
    double x;
    x=n*n;
    return x;
}
void transform(double*p1,double*p2,int n,double(*fun)(double))
{
    for(int i;i<n;i++)
    {
        p2[i]=(*fun)(p1[i]);
        printf("p2[%d] %lf\n",i,p2[i]);
    }
}

