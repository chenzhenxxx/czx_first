#include<iostream>
#include<string>
using namespace std;
int main()
{  int pos=0;
   const string s="ab2c3d7R4E6";
   string num="0123456789";
   cout<<"num:";
   while((pos=s.find_first_of(num,pos))!=string::npos)
     {
         cout<<s[pos];
         pos++;
     }
}