#include<iostream>
#include<algorithm>
using namespace std;
int book[11000];
int f[11000];
int find(int x)
{
    if(x!=f[x])
    {
        f[x]=find(f[x]);
    }
    return f[x];
}
void merge (int a,int b)
{
    int c=find(a);
    int d=find(b);
    if(c!=d)
    f[c]=d;
}
int main()
{
    int n,cnt=0,group=0;
    cin>>n;
    for(int i=1;i<11000;i++)
     f[i]=i;
    while(n--)
     {
         int k;
         cin>>k;
         int a[1000];
          for(int i=0;i<k;i++)
           {
               cin>>a[i];
               if(book[a[i]]==0)
                {   book[a[i]]=1;
                    cnt++;
                }
           }
           sort(a,a+k);
           for(int i=0;i<k-1;i++)
            {
                merge(a[i],a[i+1]);
            }
     }
           for(int i=1;i<=cnt;i++)
            {
                if(f[i]==i)
                group++;
            }
            int m;
            cin>>m;
            for(int i=0;i<m;i++)
            {   int a,b;
                cin>>a>>b;
                if(find(a)!=find(b))
                printf("N\n");
                else
                printf("Y\n");
            }
        printf("%d %d",cnt,group);
}