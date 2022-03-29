#include<stdio.h>
struct node
{
    int data;
    int next;
}nod[100000];
int book[100000];
int main()
{   int a[100000],b[100000];
    int root,n,cnt=0,m=0;
    scanf("%d %d",&root,&n);
    for(int i=0;i<n;i++)
     {   int add,dt,nt;
         scanf("%d %d %d",&add,&dt,&nt);
         nod[add].data=dt;
         nod[add].next=nt;
    }

    for(int i=root;i!=-1;i=nod[i].next)
     {
         if(!book[abs(nod[i].data)])
           {
               a[cnt++]=i;
               book[abs(nod[i].data)]=1;
           }
          else
           {
               b[m++]=i;
           }
         
     }

     for(int i=0;i<cnt;i++)
      {
          if(i==cnt-1)
           {
               printf("%05d %d -1\n",a[i],nod[a[i]].data);
           }
           else
           {
               printf("%05d %d %05d\n",a[i],nod[a[i]].data,a[i+1]);
           }
      }
      for(int i=0;i<m;i++)
      {
          if(i==m-1)
           {
               printf("%05d %d -1\n",b[i],nod[b[i]].data);
           }
           else
           {
               printf("%05d %d %05d\n",b[i],nod[b[i]].data,b[i+1]);
           }
      }
}