  int pow(int n,int m)
  {  long long s;
      if(m==1)
      return n;
      else
      s=pow(n,m-1)*n;
      return s;
      
  }
#include <stdio.h>
main()
{
    int age;
    scanf("%d",&age);
    printf("%d",(int)(age*pow(10,7)*3.156));
}