#include<iostream>
#include<algorithm>
int f[101];
int emey[101][101];
int find(int x)
{
    if(x==f[x])
    return x;
    else
    return f[x]=find(f[x]);
}
void fried(int a,int b)
{
    int a1=find(a);
    int b1=find(b);
    if(a1!=b1)
    {
        f[b1]=a1;
    }
}
int main()
{
   int n,k,m,i;
   scanf("%d %d %d",&n,&k,&m);
   for(i=1;i<=n;i++)
    f[i]=i;
    for(int j=0;j<k;j++)
     {   int a,b,c;
         scanf("%d %d %d",&a,&b,&c);
         if(c==1)
         {
             fried(a,b);
         }
         else
          {
              emey[a][b]=1;
              emey[b][a]=1;
          }
     }
      for(int i=0;i<m;i++)
      {

         int a,b;
         scanf("%d %d",&a,&b);
        if(find(a)!=find(b)&&emey[a][b]==0)
        {
            printf("OK\n");
        }
        else if(find(a)==find(b)&&emey[a][b]==0)
        printf("No problem\n");
        
        else if(find(a)==find(b)&&emey[a][b]==1)
        {
            printf("OK but...\n");
        }
        else
        printf("No way\n");
     }



}