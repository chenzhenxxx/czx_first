#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
set<int> s;
struct p
{
    char name[100];
    int num;
    int flag;
}mo[10010];
int cmp(struct p a,struct p b)
{   if(a.num!=b.num)
    return a.num>b.num;
    else
    return  a.flag<b.flag;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        s.clear();
        scanf("%s",&mo[i].name);
        int m;
        cin>>m;
        mo[i].flag=m;
        while(m--)
         {
             int a;
             cin>>a;
             s.insert(a);
         }
         mo[i].num=s.size();
    }
     sort(mo,mo+n,cmp);
     if(n<3)
     {    printf("%s",mo[0].name);
         for(int i=1;i<n;i++)
         {
          printf(" %s",mo[i].name);
         }
          for(int i=n;i<3;i++) 
         {
             printf(" -");
         }
     }
     else
     {     printf("%s",mo[0].name);
         for(int i=1;i<3;i++)
     {
          printf(" %s",mo[i].name);
     }
     }
}