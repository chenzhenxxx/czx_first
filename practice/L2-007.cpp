#include<bits/stdc++.h>
using namespace std;
struct node
{
    int id;
    int flag;
    int set;
    int area;
}people[1010];

struct ANS
{
     int id;
     int flag;
     double set;
     double area;
     int ren;
}ans[10100];
bool cmp(ANS a,ANS b)
{
    if(a.area!=b.area)
    return a.area>b.area;
    else
    return a.id<b.id;
}
int f[10000];
int have[10000];
int find(int x)
{
  if(x!=f[x])
   f[x]=find(f[x]);
   return f[x];
}
void unoin(int a,int b)
{
    int c,d;
    c=find(a);
    d=find(b);
    if(c>d)
    f[c]=d;
    else
    f[d]=c;
}
void init()
{
    for(int i=0;i<10000;i++)
    f[i]=i;
    return;
}
int main()
{   init();
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
     {
         int id,fu,mu,k,child,set,area;
         scanf("%d %d %d %d",&id,&fu,&mu,&k);
         have[id]=1;
         if(fu!=-1)
          {
              unoin(id,fu);
              have[fu]=1;
          }
          if(mu!=-1)
          {
              unoin(mu,id);
              have[mu]=1;
          }
          for(int j=0;j<k;j++)
           {
               scanf("%d",&child);
               have[child]=1;
               unoin(child,id);
           }
           scanf("%d %d",&set,&area);
           people[i].id=id;
           people[i].set=set;
           people[i].area=area;
     }
      int cnt=0;
      for(int i=0;i<n;i++)
       {
           int father=find(people[i].id);
           ans[father].id=father;
           if(ans[father].flag==0)
           {
           ans[father].flag=1;
           cnt++;
           }
           
           ans[father].ren=0;
           ans[father].set+=people[i].set;
           ans[father].area+=people[i].area;

       }
       for(int i=0;i<10000;i++){
        if(have[i]==1){
            int father=find(i);
            ans[father].ren++;
        }
       }
        printf("%d\n",cnt);
        for(int i=0;i<10000;i++)
         {
             if(ans[i].flag==1)
              {
                  ans[i].set=ans[i].set*1.0/ans[i].ren;
                  ans[i].area=ans[i].area*1.0/ans[i].ren;
              }
         }
         sort(ans,ans+10000,cmp);
         for(int i=0;i<cnt;i++)
          {
              printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].ren,ans[i].set,ans[i].area);
          }
          return 0;


}