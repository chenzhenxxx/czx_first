#include <stdio.h>
main()
{
    int data[100];
    int pt[100];
    int n,i,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    { if(i==n)
      pt[i]=0;
      else
      pt[i]=i+1;
      scanf("%d",&data[i]);
    }
     scanf("%d",&data[n+1]);
   
    t=1;
    while(t!=0)
    {  if(data[pt[t]]>data[n+1])
       {    pt[n+1]=pt[t];
            pt[t]=n+1;
            break;
       }
        
           t=pt[t];
           
       }
   t=1;
    while(t!=0)
    {
        printf("%d ",data[t]);
        t=pt[t];
    }
}