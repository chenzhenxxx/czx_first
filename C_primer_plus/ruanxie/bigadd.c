#include <stdio.h>
void bigadd(char*s1,char*s2);
main()
{
    char s1[100],s2[100];
    printf("please input two number to add?\n");
    scanf("%s %s",s1,s2);
    bigadd(s1,s2);
    return 0;

}
void bigadd(char*s1,char*s2)
{    int len1,len2,i,len;
    int a[100];
    int b[100];
    int c[101]={0};
    len1=strlen(s1);
    len2=strlen(s2);
    for(i=0;i<len1;i++)
    a[i]=s1[len1-i-1]-'0';
    for(i=0;i<len2;i++)
    b[i]=s2[len2-i-1]-'0';

    if(len1>len2)
    len=len1;
    else
    len=len2;
    for(i=0;i<len;i++)
   {
    c[i]=a[i]+b[i]+c[i];
    if(c[i]>=10)
    {
        c[i]=c[i]%10;
        c[i+1]++;
    }
   }
   if(c[len]!=0)
   printf("%d",c[len]);

   for(i=len-1;i>=0;i--)
   printf("%d",c[i]);
}
    