#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,ans=0;
    char c;
    cin>>n>>c;
    for( i=1;;i++)
     {
         if(2*i*i-1>n)
         break;
     }
     i--;
     ans=n-2*i*i+1;
     for(int j=i;j>=1;j--)
      {
          for(int m=i-j;m>=1;m--)
           {
               printf(" ");
           }
           for(int m=1;m<=2*j-1;m++)
            {
                printf("%c",c);
            }
            printf("\n");
      }

      for(int j=2;j<=i;j++)
      {
          for(int m=i-j;m>=1;m--)
           {
               printf(" ");
           }
           for(int m=1;m<=2*j-1;m++)
            {
                printf("%c",c);
            }
            printf("\n");
      }
      printf("%d",ans);

}