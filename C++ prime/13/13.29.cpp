#include<bits/stdc++.h>
using namespace std;
class HasPtr
{
    public:
    friend void print (HasPtr &);
    friend void swap (HasPtr &,HasPtr&);
    friend bool operator<(const HasPtr &a,const HasPtr &b);
    
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
bool operator<(const HasPtr &a,const HasPtr &b)
 {
     cout<<"2"<<endl;
     if(*a.ps!=*b.ps)
     return *a.ps<*b.ps;
     return a.i>b.i;
     

 }
 HasPtr::~HasPtr()
 {
     if(--*use==0)
     {
         delete use;
         delete ps;
     }
 }
inline
void swap (HasPtr & a,HasPtr& b)
{
   using std::swap;
   cout<<"1"<<endl;
    swap(a.ps,b.ps);
    swap(a.i,b.i);
}
void print (HasPtr & a)
{
  cout<<*a.ps;
}
int main()
{
    HasPtr a("hello");
    print(a);
    cout<<endl;
    HasPtr b(a);
    print(b);
    cout<<endl;
    HasPtr c("world");
    print(c);
    cout<<endl;
    swap(a,c);
    print(a);
    cout<<endl;
    vector<HasPtr> ptr;
    ptr.push_back(a);
    ptr.push_back(b);
    ptr.push_back(c);
    sort(ptr.begin(),ptr.end());
    for(auto it1=ptr.begin();it1!=ptr.end();it1++)

    {
       print(*it1);
       cout<<endl;
    }
    
}


