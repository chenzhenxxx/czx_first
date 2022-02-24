#include<iostream>
#include<algorithm>
using namespace std;
struct stu
{
    int y;
    int s;
    int e;
    int sum;
    int num;
}s[310];
bool cmp(struct stu a,struct stu b)
{
    if(a.sum==b.sum&&a.y==b.y)
     return a.num<b.num;
     else if(a.sum==b.sum)
     return a.y>b.y;
     else
      return a.sum>b.sum;
}
int main()
{
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>s[i].y>>s[i].s>>s[i].e;
       s[i].sum=s[i].y+s[i].s+s[i].e;
       s[i].num=i;
   }
     sort(s+1,s+n+1,cmp);
    for(int i=1;i<=5;i++)
    printf("%d %d\n",s[i].num,s[i].sum);

}