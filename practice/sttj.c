#include<stdio.h>
int main()
{
   long long a,b,n,day=0,sum=0,x=1,i;
   scanf("%lld %lld %lld",&a,&b,&n);
       int m=a*5+b*2;
        if(n<=m)
        {
            for(int i=1;i<=7;i++)
            {
                if(i<=5)
                sum+=a;
                else
                sum+=b;
                if(sum>=n)
                {
                    x=i;
                    break;
                }
            }
        }
        else
        {    
             x=n/m*7;
             n=n%m;
             if(n%m!=0)
             {
             for(int i=1;i<=7;i++)
            {
                if(i<=5)
                sum+=a;
                else
                sum+=b;
                if(sum>=n)
                {
                    x+=i;
                    break;
                }
            }
             }
        }
   printf("%lld",x);
}