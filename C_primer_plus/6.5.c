#include <stdio.h>
main()
{
   char a;
   char ch;
   scanf("%c",&a);
   int n,i,j;
   n=a-'A'+1;
   for(i=1;i<=n;i++)
   {
   for(j=i;j<n;j++)
   printf(" ");
   for(ch='A';ch<'A'+i-1;ch++)
   printf("%c",ch);
   for(ch='A'+i-1;ch>='A';ch--)
   printf("%c",ch);
   printf("\n");
   }


}
