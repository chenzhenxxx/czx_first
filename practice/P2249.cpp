#include<bits/stdc++.h>
using namespace std;
int v[1000010];
int n,m;
void ef(int nu)
{   int flag=0;
 int index=1;
   int begin=1;int end=n;
   while(begin<end)
   {
       int mid=(end+begin)/2;
       if(v[mid]>nu)
       {
           end=mid-1;
       }
       else if(v[mid]<nu)
       {
           begin=mid+1;
       }
       else
       {
           end=mid;
       }
      
   }
   if(v[begin]==nu)
   cout<<begin<<" ";
   else 
   cout<<-1<<" ";
   return ;
}
int main()
{   
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
    {   
        scanf("%d",&v[i]);
       
    }
    while(m--)
    {
        int nu;
        cin>>nu;
        ef(nu);
    }

}