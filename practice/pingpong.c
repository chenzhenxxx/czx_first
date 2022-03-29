#include <stdio.h>
#include <string.h>
main()
{  int i,len,countw=0,countl=0;
    char  a[100000];
    for(i=0;;i++)
    {
        scanf("%c",&a[i]);
        if(a[i]=='E'||a[i]=='\0')
        break;
    }
   len=strlen(a);


 for(i=0;i<len;i++)
    {    
        
        if(a[i]=='E')
        { printf("%d:%d\n",countw,countl);
          break;
            }
        if(a[i]=='W')
        countw++;
        if(countw>=11&&(countw-countl)>=2)
        {
            printf("%d:%d\n",countw,countl);
            countw=0;
            countl=0;
        }
        if(a[i]=='L')
        countl++;
        if(countl>=11&&(countl-countw)>=2)
        {
            printf("%d:%d\n",countw,countl);
            countw=0;
            countl=0;
        }
        
    }
printf("\n");
countw=0;
 countl=0;
    for(i=0;i<len;i++)
    {
    
        if(a[i]=='E')
        { printf("%d:%d\n",countw,countl);
          break;
            }
        if(a[i]=='W')
        countw++;
        if(countw>=21&&(countw-countl)>=2)
        {
            printf("%d:%d\n",countw,countl);
            countw=0;
            countl=0;
        }
        if(a[i]=='L')
        countl++;
        if(countl>=21&&(countl-countw)>=2)
        {
            printf("%d:%d\n",countw,countl);
            countw=0;
            countl=0;
        }
    }
}