#include<iostream>
using namespace std;
int judge(int x)
{
    while(x>0)
    {
        int tmp=x%10;
        if(tmp==2||tmp==4)
        {
            return 0;
        }
        x=x/10;
    }
    return 1;
}
int main()
{  int ans=0;
   for(int i=1;i<=2019;i++)
   {
    for(int j=i+1;j<=2019;j++)
    {
        int k=2019-i-j;
        if(k>0)
        {
        if(judge(i)&&judge(j)&&judge(k))
          {
            ans++;
          }
        }
    }
   }
    cout<<ans<<endl;

}