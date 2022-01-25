#include <stdio.h>
#include <string.h>
main()
{   int t,i;
    scanf("%d",&t);
    char a[12];
    for(i=0;i<t;i++)
    {
        int k;
        scanf("%s %d",&a,&k);
        int len=strlen(a);
        for(int r=0;r<k;r++)
        {

    
        for(int j=0;j<len;j++)
        {
            if(a[j]>a[j+1])
            {
                for(int m=j;m<len-1;m++)
                {
                    a[m]=a[m+1];
                }
                break;
            }
        }
        len--;

    }
    for(int s=0;s<len;s++)
    printf("%c",a[i]);
    printf("\n");
    }
    
}