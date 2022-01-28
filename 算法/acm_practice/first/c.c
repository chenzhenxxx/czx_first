#include <stdio.h>
main()
{
    int t;
    scanf("%d",&t);
   
    for(int i=0;i<t;i++)
     {   
         int n;
         int flag=0;
         char a[100];
         scanf("%d",&n);
         scanf("%s",&a);
         getchar();
         int book[27];
         for(int m=0;m<27;m++)
         book[m]=0;
         for(int j=0;j<n;j++)
           {  
               if(!book[a[j]-'A'])
               book[a[j]-'A']=1;
               else
               {
                   if(a[j]!=a[j-1]&&j!=0)
                   {
                       
                       flag=1;
                       break;
                   }
               }
                 
           }
           if(flag==0)
           printf("YES\n");
           else
           printf("NO\n");

     }
}