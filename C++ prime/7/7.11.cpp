#include<iostream>
#include"Sales_item.h"
#include<string>
using namespace std;
class Sales_data{
  friend istream &read(istream &is,Sales_data &item);
  friend ostream &print(ostream &os,Sales_data &item);
  private:
  string bookNo;  //编号
  unsigned units_sold; //数量
  double revenue; //总价
  public:
  string isbn() const {return bookNo;};
  Sales_data & combine(const Sales_data&);
  Sales_data()=default;
  Sales_data(const string &s): bookNo(s) {}
  Sales_data(const string &s,unsigned n,double p):
  bookNo(s),units_sold(n),revenue(p*n) {}
  Sales_data(istream &is);

};
istream &read(istream &is,Sales_data &item)
{
    double price=0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue=price*item.units_sold;
    return is;
}
ostream &print(ostream &os,Sales_data &item)
{
   cout<<item.bookNo<<" "<<item.units_sold<<" "<<item.revenue;
   return os;
}
Sales_data::Sales_data(istream &is)
{
   read(cin,*this);
}

int main()
{
    Sales_data book(cin);
    print(cout,book)<<endl;
    Sales_data book2("sisibibi",3,55.0);
    print(cout,book2)<<endl;
    Sales_data book3("myyo");
    print(cout,book3);
    
}
