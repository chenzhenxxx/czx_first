#include<bits/stdc++.h>
using namespace std;

class HasPtr
{
    public:
    HasPtr(const HasPtr& Ptr): ps(new string (*Ptr.ps)),i(Ptr.i){}
    HasPtr & operator=(const HasPtr &);
    HasPtr(const string  &s =string()):
     ps(new string(s)),i(0) {}
     ~HasPtr(){delete ps;};
    private:
    string *ps;
    int i;
};
HasPtr & HasPtr::operator=(const HasPtr & Ptr)
{
  string *p =new string(*Ptr.ps);
  delete ps;
  ps=p;
  i=Ptr.i;
  return *this;
}

