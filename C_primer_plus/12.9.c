#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main()
{   int n,i;
    printf("how many words do you wish to enter?");
    scanf("%d",&n);
    char**a=(char**)malloc(n*sizeof(char*));
    printf("\n");
    printf("Enter %d words now:\n",n);
    for(i=0;i<n;i++)
    {
        char b[100];
        scanf("%s",b);
        int s;
        s=strlen(b);
        char *str=(char *)malloc(s*sizeof(char));
        strcpy(str,b);
        a[i]=str;
    }
    for(i=0;i<n;i++)
    puts(a[i]);


}