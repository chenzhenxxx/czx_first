#include<iostream>
#include<algorithm>
using namespace std;
 struct hb
{
    int num;
    int shouru=0;
    int geshu=0;
}hoob[1000];
bool cmp(struct hb a,struct hb b)
{
    if(a.shouru!=b.shouru)
     return a.shouru>b.shouru;
      if(a.geshu!=b.geshu)
      return a.geshu>b.geshu;
       
      return a.num<b.num;

}
int main()
{
   
     int n,i;
     scanf("%d",&n);
     for(i=1;i<=n;i++)
     {   int cnt,sum=0;
         hoob[i].num=i;
         scanf("%d",&cnt);
           for(int j=0;j<cnt;j++)
             {   int peo,money;
                 scanf("%d %d",&peo,&money);
                 sum+=money;
                 hoob[peo].geshu++;
                 hoob[peo].shouru+=money;
             }
         hoob[i].shouru-=sum;

     }
     sort(hoob+1,hoob+n+1,cmp);
     for(int i=1;i<=n;i++)
      {
          printf("%d %.2f\n",hoob[i].num,hoob[i].shouru*1.0/100);
      }
}