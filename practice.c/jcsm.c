#include <stdio.h>
int jiec(int n,int data);
main()
{   int i,m,n,data;
    int t;
    int b[1001]={0};
    scanf("%d",&t);
    for(i=0;i<t;i++)
    { scanf("%d %d",&n,&data);
     b[i]=jiec(n,data);
     
    }
    for(i=0;i<t;i++)
    printf("%d\n",b[i]);
}
int jiec(int n,int data)
{
    int i,j,tmp,carry,d=1,count=0;
    int a[20000]={0};
    a[0]=1;
    for(i=2;i<=n;i++)
    {
    for(j=1,carry=0;j<=d;j++)
    
    {
         tmp=a[j-1]*i+carry;
     a[j-1]=tmp%10;
     carry=tmp/10;
    }
     while(carry)
     {
         d++;
         a[d-1]+=carry%10;
         carry=carry/10;

     }
    }
   for(i=0;i<d;i++)
   {
       if(a[i]==data)
       count++;
   }
   return count;
   

}
