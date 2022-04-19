#include<bits/stdc++.h>
using namespace std;
int prime(int n)
{
    if(n==2)
    return 1;
    for(int i=2;i<=sqrt(n)+1;i++)
     {
         if(n%i==0)
          return 0;
     }
     return 1;
}
int main()
{
    int n,i;
    cin>>n;

    if(prime(n))
     {
        printf("1\n");
        printf("%d",n);
     }
     int h=0,idx=0;
     for( i=2;i<=sqrt(n)+1;i++)
      {   
          if(n%i==0)
           {    int tmp=i;
                int cnt=1;
               for(int j=i+1;j<=sqrt(n)+1;j++)
                 {    tmp*=j;
                     if(n%tmp!=0)
                      {
                          break;
                      }
                      cnt++;
                 }
                 if(cnt>h)
                 {
                     h=cnt;
                     idx=i;
                 }

            }
      }
      printf("%d\n",h);
      printf("%d",idx);
      for(int j=idx+1;j<idx+h;j++)
      printf("*%d",j);

}