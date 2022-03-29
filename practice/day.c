#include <stdio.h>
main()
{
    int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int n,i,j,k,year,month,day;
    scanf("%d",&n);
    int final[n];
    for(i=0;i<n;i++)
    {   final[i]=0;
        scanf("%d %d %d",&year,&month,&day);
        if((year%4==0&&year%100!=0)||year%400==0)
        m[2]=29;
        for(j=1;j<year;j++)
        {
            if((j%4==0&&j%100!=0)||j%400==0)
              final[i]+=366;
            else
              final[i]+=365;
        }

        for(k=1;k<month;k++)
        final[i]+=m[k];

        final[i]+=day;
    }
   for(i=0;i<n;i++)
    printf("%d\n",final[i]);

}