#include<iostream>
#include<string>
using namespace std;
class Sale_data
{   public:
    Sale_data(string s,string n):name(s),df(n){cout<<"3"<<endl;}
    Sale_data(string s):Sale_data(){cout<<"1"<<endl;}
    Sale_data():Sale_data("chenzx","ly"){cout<<"2"<<endl;}
    private:
    string name;
    string df; 
};

int main()
{
   Sale_data s("chan");
}