#include<stdio.h>

/* 
出题人： 陈振鑫
考点： 大小端
*/
//分析代码结果，并说说你还知道哪些区别大小端的方法以及对大小端的理解。

union 
{
   int a;
   short c;       
}Pt;
int main()
{
   Pt.a=0x123412;
   char i=Pt.c;
   printf("%x\n",i);
   printf("%x\n",Pt.c);
}
