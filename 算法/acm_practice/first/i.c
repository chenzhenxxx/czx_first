#include <stdio.h>
main()
{
    int n,i,flag=0;
    scanf("%d",&n);
    for(i=0;i<n/5;i++)
    {
        if((n-7*i)%4==0&&(n+i)*3%4==0&&(n-7*i)>=0)
        {   flag=1;
            printf("%d %d %d\n",i,(n-7*i)/4,(n+i)*3/4);
        }
    }
    if(flag==0)
    printf("No Answer.");
}