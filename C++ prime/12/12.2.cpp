#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class StrBlobPtr {
   public:
   StrBlobPtr(): curr(0){}
   StrBlobPtr (StrBlob &a,size_t sz=0):wptr(a.data),curr(sz) {}
   string& deref() const;
   StrBlobPtr& incr();
   private:
    shared_ptr<vector<string>> check(size_t,const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};
class StrBlobPtr;

class StrBlob{
   public:
   friend class StrBlobPtr;
   typedef vector<string>::size_type size_type;
   StrBlob();
   StrBlob(initializer_list<string> il);//一个列表
   size_type size() const {return data->size();}
   bool empty() const {return data->empty();}
   void push_back(string &t) {data->push_back(t);}
   void pop_back();
   string& front();
   string& back();
   StrBlobPtr begin() {return StrBlobPtr(*this);}
   StrBlobPtr end() {auto ret=StrBlobPtr(*this,data->size());return ret;}
   private:
   shared_ptr<vector<string>>data;
   void check(size_type i,const string &msg) const;
};
StrBlob::StrBlob():data(make_shared<vector<string>>()){}
StrBlob::StrBlob(initializer_list<string> il):
 data(make_shared<vector<string>>(il)) {}
void StrBlob::check(size_type i,const string &msg) const{
    if(i>=data->size())
     throw out_of_range(msg);
}
string & StrBlob::front()
{
   check(0,"front on empty StrBlob");
   return data->front();
}
string & StrBlob::back()
{
   check(0,"back on the empty StrBlob");
   return data->back();
}
void StrBlob::pop_back()
{
   check(0,"pop_back on the empty StrBlob");
   data->pop_back();
}

shared_ptr <vector<string>> StrBlobPtr:: check (size_t i,const string &msg) const
{
   auto ret=wptr.lock();
   if(!ret)
   {
      throw runtime_error("unbound StrBlobPtr");
   }
   if(i>=ret->size())
   {
      throw out_of_range(msg);
   }
   return ret;

}
string& StrBlobPtr::deref() const
{
   auto p=check(curr,"dereference past end");
   return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr()
{
   check(curr,"increase past end of StrBlobPtr");
   ++curr;
   return *this;
}

