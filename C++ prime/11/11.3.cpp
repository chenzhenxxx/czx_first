#include<bits/stdc++.h>
#include<cctype>
using namespace std;
int main()
{
    map<string,size_t> word_count;
    string words;
    while(cin>>words)
    {   auto it=words.begin();
        while(it!=words.end())
         {   if(ispunct(*it))
             it=words.erase(it);//erase返回被删除容器之后的位置
             else
             {
                 *it=tolower(*it);
                 it++;
             }
         }//变成小写
         //words.erase(remove_if(words.begin(),words.end(),ispunct),words.end());
        word_count[words]++;
    }
    for(const auto &w : word_count)
    {
        cout<<w.first<<" occurs "<<w.second<<((w.second>1)?"times":"time")<<endl;
    }
}