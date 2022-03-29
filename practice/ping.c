#include<stdio.h>
main()
{
    int n,i,j;
    scanf("%d",&n);
    char a[21][10];
    for(int i=1;i<=n;i++)
    scanf("%s",&a[i]);
    for(i=1;i<=n;i++)
    for(j=i+1;j<=n;j++)
    {    char c[20];
        for(int j=0;j<)
        if(a[j][0]>a[i][0])
        {  strcpy(c,a[j]);
           strcpy(a[j],a[i]);
           strcpy(a[i],c);
        }
    }
    for(i=1;i<=n;i++)
    printf("%s",a[i]);

}