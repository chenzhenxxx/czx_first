#include <stdio.h>
#include <string.h>
main()
{  int i,lena,lenb,len;
    char a[501];
    char b[501];
    char a1[501];
    char b1[501];
    int c[502];
    for(i=0;i<502;i++)
    c[i]=0;
    scanf("%s",a);
    scanf("%s",b);
    lena=strlen(a);
    lenb=strlen(b);
    for(i=lena-1;i>=0;i--)
     {
         a1[lena-1-i]=a[i];
     }
     for(i=lenb-1;i>=0;i--)
     b1[lenb-i-1]=b[i];
     
       if(lena>lenb)
     {
         for(i=0;i<lenb;i++)
         {
             c[i]+=a1[i]+b1[i]-2*'0';
             if(c[i]>=10)
             {
                 c[i+1]+=c[i]/10;
                 c[i]=c[i]%10;
             }

          }
          for(i=lenb;i<lena;i++)
          {
              c[i]+=a1[i]-'0';
              if(c[i]>=10)
              {
                 c[i+1]+=c[i]/10;
                 c[i]=c[i]%10;
             }
          }

    }
    
    else
     {
         for(i=0;i<lena;i++)
         {
             c[i]+=a1[i]+b1[i]-2*'0';
             if(c[i]>=10)
             {
                 c[i+1]+=c[i]/10;
                 c[i]=c[i]%10;
             }

          }
          for(i=lena;i<lenb;i++)
          {
              c[i]+=b1[i]-'0';
              if(c[i]>=10)
              {
                 c[i+1]+=c[i]/10;
                 c[i]=c[i]%10;
             }
          }
    }

    len=lena>lenb?lena:lenb;
   
    if(c[len]!=0)
    printf("%d",c[len]);
    for(i=len-1;i>=0;i--)
    printf("%d",c[i]);
}
