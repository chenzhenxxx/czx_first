#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<functional>
using namespace std;
using std::placeholders::_1;
using namespace placeholders;
bool cmp(const string &s1,const string &s2)
{
   return s1.size()>s2.size();
}
void elimDups(vector<string> &words)
{
   sort(words.begin(),words.end());
   stable_sort(words.begin(),words.end(),cmp);
   auto end_position=unique(words.begin(),words.end());
   words.erase(end_position,words.end());
}
bool check_size(const string &s,string::size_type sz)
{
    return s.size()>=sz;
}
void biggies(vector<string> &words,vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(),words.end(),[](const string &a,const string &b)
    {return a.size()<b.size();});
    //auto wc=stable_partition(words.begin(),words.end(),[sz](const string a){return a.size()>=sz;});
      auto wc=stable_partition(words.begin(),words.end(),bind(check_size,_1,sz));
    auto count=count_if(words.begin(),words.end(),[sz](const string a){return a.size()>=sz;});
    cout<<count<<endl;
    for_each(words.begin(),wc,[](const string s){cout<<s<<" ";});
    

}
int main()
{
   vector<string>s={"czx","adss","czx","my","life","life"};
    //elimDups(s);
    //for(auto it=s.begin();it!=s.end();it++)
     //{
      //   cout<<*it<<" ";
     //}
     biggies(s,4);


}