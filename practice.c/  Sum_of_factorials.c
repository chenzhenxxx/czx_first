#include <stdio.h>
int a[100];
int h[100];
 void add()
 {
    int left=0;
     for(int i=1;i<=100;i++)
     {
         h[i]=h[i]+a[i];
         if(h[i]>=10)
         h[i+1]+=h[i]/10;
         h[i]=h[i]%10;
     }
 }
 void mulitipy(int x)
 {   
     int left=0;
     for(int i=1;i<=100;i++)
     {
         a[i]=a[i]*x+left;
         left=a[i]/10;
         a[i]=a[i]%10;
     }


 }

  void put()
  {   int b,i,j;
      for( i=100;i>=1;i--)
      {
          if(h[i]!=0)
           {
               b=i;
               break;
           }
      }
      for( j=b;j>=1;j--)
      printf("%d",h[j]);


  }
 main()
 {
     
     a[1]=1;
     int i,n;
     scanf("%d",&n);
     for(i=1;i<=n;i++)
     {
         mulitipy(i);
         add();
     }
     put();
 }
