#include <stdio.h>
main()
{  int len,i,sum=0,k=1,h;
  char a[14];
  gets(a);
  len=strlen(a);
  for(i=0;i<len-1;i++)
   if(a[i]!='-')
   {sum+=(a[i]-'0')*k;
   k++;
   }
  h=sum%11;
  if(h==10)
{
  if(a[12]=='X')
  printf("Right\n");
  else
  {
    for(i=0;i<len-1;i++)
  printf("%c",a[i]);
  printf("X");
  }
}
else
{
   if((a[12]-'0')==(h))
   printf("Right");
   else
   {
   for(i=0;i<len-1;i++)
   printf("%c",a[i]);
   printf("%d",h);
}
}
}