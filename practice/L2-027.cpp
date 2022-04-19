#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct stu
{
    string s;
    int grade;
}s[50010];
int  cmp(struct stu a,struct stu b)
{
    if(a.grade!=b.grade)
     {
         return a.grade>b.grade;
     }
     else
     return a.s<b.s;
}
int main()
{
   int n,g,k,money=0;
   cin>>n>>g>>k;
   for(int i=1;i<=n;i++)
    {
        cin>>s[i].s>>s[i].grade;
         if(s[i].grade<g&&s[i].grade>=60)
         money+=20;
         else if(s[i].grade>=g)
         money+=50;

    }
    sort(s+1,s+n+1,cmp);
    printf("%d\n",money);
    int num=0;
    for(int i=1;i<=n;i++)
    {   
        if(s[i-1].grade!=s[i].grade)
         {
            num=i;
         }
         if(num>k)
          break;
          cout<<num<< " "<<s[i].s<< " "<< s[i].grade<<endl;
    }
}