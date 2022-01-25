#include<stdio.h>
main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);
    int a[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    int sum;
    sum=m*n;
    for(i=0;i<n-1;i++)
    {
        if(a[i]+m>a[i+1])
        {
            sum-=(a[i]+m-a[i+1]);
        }
    }
    printf("%d",sum);
}
   int len=strlen(a);

     char min=a[0];
     int k=0;
    for(  j=1;j<len;j++)
    {
        if(min>a[j])
         {
             min=a[j];
             k=j;
         }

    }
    printf("%c ",a[k]);
    for(int m=0;m<len;m++)
    {
        if(m!=k)
        printf("%c",a[m]);
    }
    printf("\n");
    }