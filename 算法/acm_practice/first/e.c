#include <stdio.h>
main()
{
    int w,count=0,c=0;
    scanf("%d",&w);
    int n,i,j,t;
    scanf("%d",&n);
    int a[n+1];
    for(i=0;i<n;i++)
    { 
        scanf("%d",&a[i]);

    }

    for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
    {
        if(a[i]<a[j])
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        
        }
    }
      i=0;j=n-1;
    while(i<=j)
    {
        if(a[i]+a[j]<=w)
        {
            i++;
            j--;
         }
         else
         i++;
         c++;
    }
   printf("%d",c);

}