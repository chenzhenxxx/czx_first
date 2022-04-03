#include<stdio.h>
int f[6000];
 int n,m,p;
void init()
{
    for(int i=1;i<=n;i++)
    f[i]=i;
}
int find(int x)
{
    if(f[x]!=x)
    f[x]=find(f[x]);
    return f[x];
}
void merge(int a,int b)
{
    int c=find(a);
    int d=find(b);
    if(c!=d)
    f[c]=d;
}
main()
{
   
    scanf("%d %d %d",&n,&m,&p);
    init();
    while(m--)
     {  
         int a,b;
         scanf("%d %d",&a,&b);
         merge(a,b);
     }
     
     while(p--)
      {
          int a,b;
          scanf("%d %d",&a,&b);
          if(find(a)!=find(b))
           printf("No\n");
           else
           printf("Yes\n");
      }
}