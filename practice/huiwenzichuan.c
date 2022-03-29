#include <stdio.h>
#include <string.h>

main()
{  int len,i,j,k,m;
   char a[20000];
   scanf("%s",&a);
   len=strlen(a);
   for( i=2;i<=len;i++)
   {   int flag=0;
       int maxlen=len-i;
       for(j=0;j<=maxlen;j++)
        {
            m=j+i-1;
            for(k=j;k<m;k++,m--)
            {
                if(a[k]!=a[m])
                break;
            }
            if(k>=m)
          {
             m=j+i-1;
           for(int q=j;q<=m;q++)
            printf("%c",a[q]);
            printf("\n");
          }
        
           
       
   }
   }
   
    
}