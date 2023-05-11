#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
  // 请在此输入您的代码
  map<char,int> ans;
  string s;
  cin>>s;
  for(char c:s)
  {
     ans[c]++;
  }
  char m;
  int maxx=0;
  for(char c = 'a';c<='z';c++)
  {
       if(maxx<ans[c])
       {
        maxx=ans[c];
        m=c;
       }
  }
  cout<< m <<endl;
  cout << maxx <<endl;
  return 0;
}