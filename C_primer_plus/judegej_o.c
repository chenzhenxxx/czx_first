#include <stdio.h>
main()
{  int n;
  scanf("%d",&n);
  if((n&1)==0)
  printf("偶数\n");
  else
  printf("奇数\n");
}