#include<iostream>
#include<algorithm>

using namespace std;
int a[1010];
int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    int k;
    cin>>k;
    while(k--)
    {
      int t;
      cin>>t;
      a[t]++;
    }

  }
  int max=1;
  int index=1000;
  for(int i=1009;i>=0;i--)
  {
      if(a[i]>max)
      {
        max=a[i];
        index=i;
      }
  }
  printf("%d %d",index,max);
}