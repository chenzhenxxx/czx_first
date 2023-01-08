#include<bits/stdc++.h>
using namespace std;
set<int> s;
int main()
{
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(5);
  s.insert(8);
  auto it=s.begin();
  while(s.size()<2020)
  {
    s.insert(3*(*it)+2);
    if(s.size()==2020)
    break;
    s.insert(5*(*it)+3);
    if(s.size()==2020)
    break;
    s.insert(8*(*it)+5);
    if(s.size()==2020)
    break;
    *it++;
  }
  it=s.end();
  it--;
  cout<<*it;

}