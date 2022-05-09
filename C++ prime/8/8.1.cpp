#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
string word;
vector<string> v;
istream & read(istream& is)
{   string mm;
    while(!is.eof()&&cin>>mm)
    {
        cout<<mm<<endl;
    }
    is.clear();
    return is;
}
istream& readd(istream& is)
{   string s;
    while(getline(cin,s))
     { 
        istringstream record(s);
        while(record>>word)
         {
           cout<<word<<ends;
         }
     }
     return is;
}
int main()
{      
       readd(cin);
      
}