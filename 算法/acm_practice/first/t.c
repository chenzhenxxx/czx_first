#include <stdio.h>
int book[100]={0};
main()
{
     char name[65][100];
    char pt[65][100];
    int n,i,j;
    int k=0;
     int begin,q,t,count=1,f=0;
    scanf("%d",&n);
    for( i=0;i<n;i++)
    scanf("%s",name[i]); 
  
    scanf("%d,%d",&begin,&q);
    t=begin-1;
    while(n!=0)
    {
        t=(t+q-1)%n;
        puts(name[t]);
        for(j=t;j<n;j++)
         {
             name[j][0]='\0';
             strcpy(name[j],name[j+1]);
         }
         n--;
         if(t==n)
         t=1;

    }
        
    }

   
    
