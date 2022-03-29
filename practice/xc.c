#include <stdio.h>
#include <string.h>
main()
{
    char a[200];
    char b[200];
    int lena,lenb,len,i,j,tmp1,tmp2,cheng=0,jia=0,t;
    gets(a);
    gets(b);
    lena=strlen(a);
    lenb=strlen(b);
    len=lena+lenb;
    int c[len];
    memset(c,0,sizeof(c));

     for(i=0;i<lena/2;i++)
    {  t=a[i];
       a[i]=a[lena-1-i];
       a[lena-1-i]=t;

    }

    for(i=0;i<lenb/2;i++)
    {  t=b[i];
       b[i]=b[lenb-1-i];
       b[lenb-1-i]=t;

    }

    for(i=0;i<lena;i++)
     {  jia=0;
        cheng=0;
         for(j=0;j<lenb;j++)
        {
            tmp1=(a[i]-'0')*(b[j]-'0')+cheng;
            cheng=tmp1/10;
            tmp1=tmp1%10;
            tmp2=tmp1+jia+c[i+j];
            jia=tmp2/10;
            c[i+j]=tmp2%10;
        }
        c[lenb+i]+=cheng+jia;

     }
      int flag=0;
     for(i=len-1;i>=0;i--)
     {
         if(c[i]!=0)
         flag=1;
         if(flag==1)
         printf("%d",c[i]);
     }
     if(flag==0)
     printf("0");

} 