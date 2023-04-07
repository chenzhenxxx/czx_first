#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int ans=0;
  for(int i=1;i<=2020;i++)
  {
    int tmp=i;
    while(tmp>0)
    {
      int m=tmp%10;
      if(m==2)
      {
        ans++;
      }
      tmp=tmp/10;
    }
  }
  cout<<ans<<endl;
  return 0;
}