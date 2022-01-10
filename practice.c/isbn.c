#include <stdio.h>
main()
{
   int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
   int n,i,year,month1,day,count=0;
   int prt[100]={0};
   scanf("%d",&n);
   for(int k=0;k<n;k++)
   {
       scanf("%d %d %d",&year,&month1,&day);
       if((year%4==0&&year%100!=0)||year%400==0)
        month[2]=29;
        for(int k=1;k<year;k++)
        
        {  if((k%4==0&&k%100!=0)||k%400==0)
            prt[count]+=366;
            else
             prt[count]+=365;
        }
        for(i=1;i<month1;i++)
        {
            prt[count]+=month[i];
        }
        prt[count]+=day;
        count++;
     }

 for(i=0;i<n;i++)
 printf("%d\n",prt[i]);
}