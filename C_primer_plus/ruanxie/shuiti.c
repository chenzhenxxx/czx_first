#include <stdio.h>
main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        if(n==k)
        printf("0\n");
        else if(k>n)
        printf("%d\n",k-n);
        else 
        {
            if(k%2==n%2)
            printf("0\n");
            else 
            printf("1\n");
        }
        
    } 
}