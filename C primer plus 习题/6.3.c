#include <stdio.h>
main()
{
    int i,n;
    char ch;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    for(ch='F';ch>='F'-i;ch--)
    printf("%c",ch);
    printf("\n");
    }
}