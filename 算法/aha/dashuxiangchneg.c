#include <stdio.h>
#include <stdio.h>
main()
{   char t;
    char a[5000];
    char b[5000];
    scanf("%s",a);
    scanf("%s",b);
    int lena,lenb,i;
    lena=strlen(a);
    lenb=strlen(b);
    char c[lena+lenb+1];
    memset(c, '0', lena+lenb);
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
    
    int tmp1,tmp2;
    for(i=0;i<lena;i++)
    {
        int cw=0,jw=0;
    for(int j=0;j<lenb;j++)
    {  tmp1=(a[i]-'0')*(b[j]-'0')+cw;
       cw=tmp1/10;
       tmp1=tmp1%10;
       
       tmp2=c[i+j]-'0'+tmp1+jw;
       jw=tmp2/10;
       c[i+j]=tmp2%10+48;

    }
    c[i + lenb] += jw+cw;
    }

    int flag=0;
    for(i=lena+lenb-1;i>=0;i--)
    {   if(c[i]!='0')
        flag=1;
        if(flag==1)
        printf("%c",c[i]);
    }
    if(flag==0)
    printf("0");

}