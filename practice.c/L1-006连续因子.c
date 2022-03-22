#include<stdio.h>
#include<math.h>
long long isprime(long long n)
{
    if(n==2)
    return 1;
    else
    {
        for(long long i=2;i<=sqrt(n)+1;i++)
         {
             if(n%i==0)
             return 0;
         }
    }
    return 1;
}
int  main()
{
    long long n,i,j,h=0,cnt=0,m=2;
    scanf("%lld",&n);
    if(isprime(n))
     {
         printf("1\n");
         printf("%lld",n);
         return 0;
     }
     else
     {
         for(i=2;i<=sqrt(n)+1;i++)
          {    
               if(n%i==0)
                {   
                    long long tmp=i;
                     for(j=i+1;j<=sqrt(n)+1;j++)
                      {    cnt++;
                          tmp*=j;
                          if(n%tmp!=0)
                           {  
                               break;
                           }
                           
                      }
                      if(cnt>h)
                  {
                      h=cnt;
                      m=i;
                  }
                  cnt=0;
                }
                
          }
          printf("%lld\n",h);
          printf("%lld",m);
         
          for(j=m+1;j<h+m;j++)
           printf("*%lld",j);
          
          
           
     }
}