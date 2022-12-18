#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
  // 请在此输入您的代码
  long long a[100100];
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  cin>>a[i];
  sort(a+1,a+n+1);
  long tmp=a[2]-a[1];
  for(int i=3;i<=n;i++)
  {
      int x=a[i]-a[i-1];
      if(x<tmp)
      tmp=x;
  }
  if(tmp==0)
  printf("%d",n);
  else
  {
  printf("%lld\n",(a[n]-a[1])/tmp+1);
  }
  return 0;
}