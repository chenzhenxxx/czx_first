#include<stdio.h>
#include<string.h>
swap(char *a,char *b)
{
  char temp=*a;
  *a=*b;
  *b=temp;
}
fun(char data[99],int k)
{
    int i;
    if(k==strlen(data)-1)
    printf("%s\n",data);
    else
    {
      for(i=k;i<=strlen(data)-1;i++)
      {
        swap(&data[i],&data[k]);
        fun(data,k+1);
        swap(&data[i],&data[k]);
      }
    }
}
main()
{
  char data[99];
  scanf("%s",data);
  fun(data,0);
  return 0;
}