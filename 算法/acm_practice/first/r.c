#include <stdio.h>
#include <string.h>
main()
{
    int t,i,count=0;
    char n[20];
    char a[1000][12];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {   int k,j,m;
        scanf("%s %d",&n,&k);
        int len=strlen(n);
          for(j=0;j<k;j++)
          {
              for(m=0;m<len-1;m++)
                {
                    if(n[m]>n[m+1])
                    {
                        for(int x=m;x<len-1;x++)
                          {
                              n[x]=n[x+1];
                          }
                          break;
                    }
                }
            len--;
          }
          for(int q=0;q<len;q++)
           a[count][q]=n[q];
           count++;


    }
    for(int i=0;i<count;i++)
     puts(a[i]);
}