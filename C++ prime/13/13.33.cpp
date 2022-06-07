#include<bits/stdc++.h>
using namespace std;
class StrVec
{
  public:
   StrVec(): elements(nullptr),first_free(nullptr),cap(nullptr) {}
   StrVec(const StrVec &);
   void reserve(size_t new_cap);
   void alloc_n_move(size_t new_cap);
    StrVec &operator=(const StrVec&);
    ~StrVec();
    void push_back(const string&);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap -elements;}
    string *begin() const {return elements;}
    string *end() const {return first_free;}

    private:
    static allocator<string> alloc;
    void chk_n_alloc()
     {
         if(size()==capacity())
         reallocate();
     }
    pair<string*,string*> __alloc_on_copy(const string*,const string*);
    void free();
    void reallocate();
    string *elements;
    string* cap;
    string *first_free;
};
void StrVec::push_back(const string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++,s);
}
pair<string*,string*> StrVec:: __alloc_on_copy(const string* b,const string* e)
{
   auto data =alloc.allocate(e-b);
   return {data,uninitialized_copy(b,e,data)};
}
void StrVec:: free (){
    if(elements)
    {
        //for(auto p=first_free;p!=elements;)
        //{
          //  alloc.destroy(--p);
            // alloc.deallocate(elements,cap-elements);
        //}
        for_each(elements,first_free,[this](std::string&rhs) {alloc.destroy(&rhs);});
        alloc.deallocate(elements,cap-elements);
    }

}
StrVec::StrVec(const StrVec &s)
{
    auto newdata=__alloc_on_copy(s.begin(),s.end());
    elements=newdata.first;
    first_free=cap=newdata.second;
}
StrVec &StrVec::operator=(const StrVec &rhs)
{
    auto data=__alloc_on_copy(rhs.begin(),rhs.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}
void StrVec::reallocate ()
{
    auto newcapacity=size()?2*size():1;
    auto newdata=alloc.allocate(newcapacity);
    auto dest=newdata;
    auto elem=elements;
    for(size_t i=0;i!=size();i++)
    
        alloc.construct(dest++,std::move(*elem++));
    free();
    elements=newdata;
    first_free=dest;
    cap=elements+newcapacity;
}
void StrVec::reserve(size_t new_cap)
{
    if(new_cap<=capacity()) return ;
    alloc_n_move(new_cap);
}
void StrVec::alloc_n_move(size_t new_cap)
{
    auto newdata=alloc.allocate(new_cap);
    auto dest=newdata;
    auto elem=elements;
    for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + new_cap;
}