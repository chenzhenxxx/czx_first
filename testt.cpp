#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{ vector<int> nums;
  int n;
  int ok=0;
  int great=0;
  cin>>n;
  for(int i=0;i<n;i++)
  { int x;
    cin>>x;
    nums.push_back(x);
    if(nums[i]>=60)
    {
      ok++;
    }
    if(nums[i]>=85){
      great++;
    }
  }
  double ans1= ok*100.0/n;
  int tmp=ans1;
  tmp= (ans1-tmp)>=0.5?tmp+1:tmp;
  cout<<tmp<<"%"<<endl;
  double ans2= great*100.0/n;
  tmp=ans2;
  tmp= (ans2-tmp)>=0.5?tmp+1:tmp;
  cout<<tmp<<"%"<<endl;
  // 请在此输入您的代码
  return 0;
}