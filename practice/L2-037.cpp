#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn =1000+5;
queue<char>que[maxn];
stack<char>s;
int main()
{
    int n,h,smax;
    scanf("%d %d %d",&n,&h,&smax);

    for(int i=1;i<=n;i++)
     for(int j=1;j<=h;j++)
       {  char c;
          cin>>c;
          que[i].push(c);
       }
      
       int m;
      while(cin>>m)
       {  if(m==-1)
          break;
          if(m==0)
           {
               if(!s.empty())
               {
                   cout<<s.top();
                   s.pop();
               }

           }
           else 
            {
                if(que[m].empty())
                 continue;

                 if(s.size()==smax)
                  {
                      cout<<s.top();
                      s.pop();
                  }


                   
            }
            s.push(que[m].front());
            que[m].pop();
       }
    return 0;
}