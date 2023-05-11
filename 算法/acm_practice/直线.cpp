#include <iostream>
#include <set>
using namespace std;
int main()
{ set<pair<double,double>> s;
  // 请在此输入您的代码
  for(int i=0;i<20;i++)
  {
    for(int j=0;j<21;j++)
    {
      for(int k=i+1;k<20;k++)
      {
        for(int m=0;m<21;m++)
        {
          if(i-k!=0&&j-m!=0)
          { double kk=(double)(j-m)/(i-k);
            double bb=(double)(i*m-j*k)/(i-k);
            s.insert({kk,bb});
          }
        }
      }
    }
  }
  cout<<s.size()+41<<endl;
  return 0;
}

