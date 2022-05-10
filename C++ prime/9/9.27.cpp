#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
   forward_list<int> l{1,2,3,4,5};
   auto prev=l.before_begin();
   auto curr=l.begin();
   while(curr!=l.end())
   {
       if(*curr&1)
       {
           curr=l.erase_after(prev);

       }
       else
       {
           prev=curr;
           curr++;
       }
   }
   for(auto x=l.begin();x!=l.end();x++)
   cout<<*x<<" ";
}