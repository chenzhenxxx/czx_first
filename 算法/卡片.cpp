#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int flag[10];
  int cnt=0;
  int aa=1;
  for(int i=0;i<=9;i++)
  {
    flag[i]=2021;
  }
  for(int i=0;i<1000000;i++)
  { 
    int tmp=i;
    if(tmp==0)
    {
        flag[0]--;
        cnt++;
        continue;
    }
    while(tmp>0)
    {
    int m=tmp%10;
    flag[m]--;
    if(flag[m]==0)
    { aa=0;
      break;
    }
    tmp=tmp/10;
    }
    if(aa==0)
    {
        break;
    }
    cnt++;
  }
  cout<<cnt<<endl;
  return 0;
}