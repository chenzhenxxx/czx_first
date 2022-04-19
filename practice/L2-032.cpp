#include<bits/stdc++.h>
using namespace std;
queue<int>q;
stack<int>s;
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    while(k--)
     {   while(!q.empty()) q.pop();
          while(!s.empty()) s.pop();
         int cnt=1;
        for(int i=0;i<n;i++)
         {
             int x;
             cin>>x;
             q.push(x);
         }

         while(!q.empty()||s.size()!=0)
          {  
               if(q.empty()&&s.top()!=cnt)
             {
                 break;
             }
              
              else  if(s.size()!=0&&s.top()==cnt)
               {
                   s.pop();
                   cnt++;
                   
               }
              else if(q.front()==cnt&&!q.empty())
               {
                   cnt++;
                   q.pop();
                   
               }
               else if(!q.empty()&&q.front()!=cnt) 
               {
                   s.push(q.front());
                   q.pop();
               }
               if(s.size()>m)
                break;
 
          }
          if(s.size()!=0||!q.empty())
           {   
               printf("NO\n");
           }
           else
           {
              printf("YES\n");
           }

     }
}