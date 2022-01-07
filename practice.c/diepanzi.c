#include <stdio.h>
main()
{
    int n,m,count=0,j,i;
    scanf("%d %d",&n,&m);
    int jin[n+1];
    int p[m+1];
    for( i=1;i<=n;i++)
    scanf("%d",&jin[i]);
    for( j=1;j<=m;j++)
    scanf("%d",&p[j]);


    int x=n;
    for(j=1;j<=m;j++)
    {    int flag=0;
        for( i=1;i<=x;i++)
        {
            if(jin[i]<p[j])
          { printf("%d %d\n",jin[i],p[j]);
              flag=1;
               break;
          }
        }
    if(flag==0)
    x=x-1;
    else
    x=i-1;
    if(x<1)
    break;
    count++;
    }
    printf("%d",count);
}