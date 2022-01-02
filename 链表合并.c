#include <stdio.h>
main()
{
    char *p[7];
    char b[11][20];
    int i,n,flag=1;
    char a[7][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Thursday","Friday","Saturday"};
    for(i=0;i<6;i++)
    p[i]=a[i];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    { flag=1;
        sacnf("%s",b[i]);
        for(j=0;j<7;j++)
        {  
            if(strcmp(p[i],b[i])==0)
            {   flag=0;
                printf("%d\n",i+1);
                break;
            }
        }
        if(flag==1)
        printf("-1\n");

        
    }

}