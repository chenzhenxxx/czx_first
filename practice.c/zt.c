#include <stdio.h>
main()
{
    int n,i,j;
    scanf("%d",&n);
    char a[n+1][101];
    for(i=1;i<=n;i++)
     scanf("%s",&a[i]);
      int max=1;
       for(i=2;i<=n;i++)
        {   if(strlen(a[max])>strlen(a[i]))
           continue;
            else if (strlen(a[max])<strlen(a[i]))
            { max=i;
                
            }
            
            else
            {
            if(strcmp(a[max],a[i])<0)
        {
            max=i;
        }
            }
        }
    printf("%d\n",max);
    printf("%s",a[max]);

}