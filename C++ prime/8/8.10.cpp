#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
string word;
vector<string> v;

ifstream& readd(ifstream& is)
{   string s;
    while(getline(is,s))
     { 
        v.push_back(s);
     }
     for(int i=0;i<v.size();i++)
      {
          istringstream s(v[i]);
          while(s>>word)
           {
               cout<<word<<ends;
           }
      }
     return is;
}
int main()
{      ifstream inn("/home/chenzhenxin/1.txt");
       if(inn)
       {
       readd(inn);
       }
      
}