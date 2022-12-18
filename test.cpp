#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int a[10000];
  int n;
  cin>>n;
  for(int i=1;i<=n/2;i++)
  {
    a[n-i+1]=a[i]=(n-i)*2;
  }
  for(int i=1;i<=n;i++)
  printf("%d\n",a[i]);
  return 0;
}