#include <iostream>
using namespace std;
int main()
{
  // 请在此输入您的代码‘
  int n;
  int cnt=0;
   cin>>n;
  int a[n+1];
  for(int i=n;i>=1;i--)
  cin>>a[i];
  for(int i=1;i<=n;i++)
  {
    if(a[i]==a[i+1])
    {
      a[i+1]++;
      cnt++;
    }
    if(a[i]>a[i+1])
    {
      a[i]=a[i+1]-1;
      cnt++;
    }
  }
  cout<<cnt;
  return 0;
}
