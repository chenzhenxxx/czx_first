#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
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
int main()
{
   vector<string>s={"czx","adss","czx","my","life","life"};
    elimDups(s);
    for(auto it=s.begin();it!=s.end();it++)
     {
         cout<<*it<<" ";
     }


}