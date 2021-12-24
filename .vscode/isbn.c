#include <stdio.h>
void quicksort(int*a,int begin,int end)
{
    int i,j,tmp,t;
    i=begin;
    j=end;
    tmp=a[begin];
    if(i>j)
    return;
    while(i!=j)
    {
        while(a[j]>=tmp&&j>i)
        j--;
        while(a[i]<=tmp&&j>i)
        i++;
        if(j>i)
        { t=a[i];
        a[i]=a[j];
        a[j]=t;
            
        }
    }
    a[begin]=a[i];
    a[i]=tmp;
    quicksort(a,begin,i-1);
    quicksort(a,i+1,end);
    return;
}
main()
{
    int n,i,count=0;
    printf("please input a number:\n");
    scanf("%d",&n);
    int a[n];
    int c[n];
    for(i=0;i<n;i++)
     scanf("%d",&a[i]);
     int b[1001];
     for(i=0;i<1001;i++)
     b[i]=0;
     for(int i=0;i<n;i++)
     if(b[a[i]]==0)
     {
         c[count++]=a[i];
         b[a[i]]=1;
     }
    
      quicksort(c,0,count-1);
     printf("the count:%d\n",count);
     for(i=0;i<count;i++)
     printf("%d",c[i]);

}