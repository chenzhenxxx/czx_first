#include <stdio.h>
#include <string.h>
#include <stdlib.h>
main()
{
    int n,i,j;
    scanf("%d",&n);
    char a[n][102];
    for(i=0;i<n;i++)
    scanf("%s",a[i]);

    for(i=0;i<n;i++)
    {
        int k=0;
        char min=a[i][0];
        int len=strlen(a[i]);
        for(j=1;j<len;j++)
          {
              if(min>a[i][j])
              {
                  min=a[i][j];
                   k=j;
              }
          }
          printf("%c ",a[i][k]);
          for(int m=0;m<len;m++)
          {
              if(m!=k)
              printf("%c",a[i][m]);
          }
          printf("\n");
    } 
}