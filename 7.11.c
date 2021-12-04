#include <stdio.h>
main()
{   char ch;
float yang,tian,hu,sumyang=0,sumhu=0,sumtian=0,sum=0,money,other;
  printf("a)yang     b)tian\n");
  printf("c)hu       q)qiut\n" );
  printf("please input zhonglei\n");
  printf("66");
  while(scanf("%c",&ch)==1&&ch!='q')
  {
     switch(ch)
     {
        case 'a' :printf("the yang you want:\n");
                  scanf("%f",&yang);
                  sumyang+=yang;
                  break;
         case 'b' :printf("the tian you want:\n");
                  scanf("%f",&tian);
                  sumtian+=tian;
                  break;
         case 'c' :printf("the hu you want:\n");
                  scanf("%f",&hu);
                  sumhu+=hu;
                  break;
      }
  printf("a)yang     b)tian\n");
  printf("c)hu       q)qiut\n" );
  printf("please input zhonglei\n");
  getchar();

  }
  printf("yang$2.05      tian$1.15     hu$1.09\n");
  sum=sumyang+sumhu+sumtian;
  money=sumyang*2.05+sumtian*1.15+sumhu*1.09;
  printf("the total weight:\n");
  printf("yang: %f\n",sumyang);
  printf("tian: %f\n",sumtian);
  printf("hu:   %f\n",sumhu);
  if(money>100)
  {money*=0.95;
  printf("sale :5%       the cost:%f",money);
  }
  else
  printf("no sale         the cost:%f",money);
  if(sum<=5)
  {
  other=6.5;
  printf("the other cost :%f",other);
  }
  else if(sum<=20)
  {
  other=14;
  printf("the other cost :%f",other);
  }
  else
  {
  other=14+(sum-20)*0.5;
  printf("the other cost :%f",other);
  }
         printf("the final cost you need pay :%f",money+other);
         printf("commit:\n");
}