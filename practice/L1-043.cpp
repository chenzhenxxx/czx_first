#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1e3+5;
int book[maxn];
void init(int *book)
{
    for(int i=0;i<maxn;i++)
    {
        book[i]=-1;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int day=0;
    init(book);
    int alltime=0,cnt=0;
    while(day<n)
    {
        int num;
        char c;
        int h,m;
        scanf("%d %c %d:%d",&num,&c,&h,&m);

        if(num==0)
         {   int ave;
             if(cnt==0)
             ave=0;
             else
             {
                 ave=(alltime*1.0)/cnt+0.5;
             }
             printf("%d %d\n",cnt,ave);
             init(book);
             alltime=0;
             cnt=0;
             day++;
         }
         else
         {
             if(c=='S')
              {
                  book[num]=h*60+m;

              }
              if(c=='E'&&book[num]!=-1)
              {
                  alltime+=(h*60+m)-book[num];
                  cnt++;
                  book[num]=-1;
              }
         }

    }

}

