#include<iostream>
#include<string>
using namespace std;
void change(string &s,string &oldval,string& newval)
{
    int _size=oldval.size();
    int _size1=newval.size();
    string::iterator it1=s.begin();
    string::iterator it2=newval.begin();
    string::iterator it3=newval.end();

     for(it1;it1<=(s.end()-oldval.size()+1);it1++)
      {
          if(s.substr(it1-s.begin(),_size)==oldval)
           {
               it1=s.erase(it1,it1+_size);
               s.insert(it1,it2,it3);
           advance(it1,_size1);
           }
      }
}
int main()
{
string s = "abcdefg";  
	string oldval = "bc";  
	string newval = "asas";  
	change(s,oldval,newval);  
	cout<<s<<endl;  
	system("pause");
	return 0;  
}