#include<bits/stdc++.h>
using namespace std;
class HasPtr
{
    public:
    HasPtr(const string s=string()):
    ps(new string(s)),i(0),use(new size_t(1)) {}
    HasPtr(const HasPtr &Ptr):
    ps(Ptr.ps),i(Ptr.i),use(Ptr.use) {++*use;}
    HasPtr & operator=(const HasPtr &);
    ~HasPtr();
    private:
    string *ps;
    int i;
    size_t *use;

};
 HasPtr & HasPtr::operator=(const HasPtr &ptr)
 {
     
     //*ptr.use++; //不能这样，因为++的优先级比*高
     (*ptr.use)++;
     if(--*use==0)
     {
         delete ps;
         delete use;
     }
     ps=ptr.ps;
     i=ptr.i;
     use=ptr.use;
     return *this;

 }
 HasPtr::~HasPtr()
 {
     if(--*use==0)
     {
         delete use;
         delete ps;
     }
 }


