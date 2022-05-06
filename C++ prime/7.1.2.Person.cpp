#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
class Person
{   friend  istream& get(istream& is,Person&me);
    friend  ostream& print(ostream &os,Person &p);
   private:
    string name;
    string address;
    public:
    Person(const string &s):name(s){}
    Person(const string &a,const string &b):name(a),address(b){}
    Person (istream &is);
    void getPerson ();
};
istream& get(istream& is,Person&me)
{
  is>>me.name>>me.address;
  return is;
}
Person::Person (istream &is)
{
  get(cin,*this);
}
ostream& print(ostream &os,Person &p)
{
  os<<p.name<<"from"<<p.address;
  return os;
}
int main()
{
Person me("chenzhenxin","longyan");
 print(cout,me);
 Person she(cin);
 print(cout,she);

}