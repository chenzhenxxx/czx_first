#include<iostream>
#include<algorithm>
using namespace std;
struct lie
{
    int l;
    int r;

} s[50005];
bool cmp(struct lie a,struct lie b)
{   if(b.l==a.l)
    return (b.r>a.r);
    else   
    return (b.l>a.l);
}
int main()
{
   int n,i,flag=1,max,min;
   cin>>n;
   for(i=0;i<n;i++)
   cin>>s[i].l>>s[i].r;
   sort(s,s+n,cmp);
   max=s[0].r;
   min=s[0].l;
   int ans=s[0].r;
   for(i=1;i<n;i++)
   {
      if(s[i].r>ans)
      {
          if(s[i].l>ans)
          {    flag=0;
              break;
          }
          else
          {
              ans=s[i].r;
          }
      }

   }
   if(flag==1)
   printf("%d %d",s[0].l,ans);
   else
   printf("no\n");

}