#include <stdio.h>
main()
{
    int n;
    scanf("%d",&n);
    //if(a<6)
    //{
       // printf("0")
    //}
    for(int a=2;a<=n;a++)
    for(int b=2;b<a;b++)
    for(int c=b;c<a;c++)
    for(int d=c;d<a;d++)
    {
        if((a*a*a)==(d*d*d+b*b*b+c*c*c)&&b<=c&&c<=d)
        printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
    }
}