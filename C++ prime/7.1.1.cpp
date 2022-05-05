#include<iostream>
#include"Sales_item.h"
#include<string>
using namespace std;
struct Sales_data{
  Sales_data();
  string bookNo;  //编号
  unsigned units_sold; //数量
  double revenue; //总价
  string isbn() const {return bookNo;};
  Sales_data & combine(const Sales_data&);
  double ave_price() const;
  
};
Sales_data&  Sales_data::combine(const Sales_data&rhs)
{
    units_sold+=rhs.units_sold;
    revenue+=rhs.revenue;
    return *this;
}
double Sales_data::ave_price() const{
    if(units_sold)
     {
         return revenue*1.0/units_sold;
     }
     else
     {
         return 0;
     }

}
Sales_data::Sales_data()
{
   units_sold=0;
   revenue=0.0;
}
istream &read(istream &is,Sales_data &item)
{
    double price=0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue=price*item.units_sold;
    return is;
}
ostream &print(ostream &os,const Sales_data &item)
{
    os<<"binahao "<<item.isbn()<<"total  "<<item.units_sold<<"total price "<<item.revenue<<"average"<<item.ave_price();
    return os;
}
Sales_data add(const Sales_data &lhs,const Sales_data &rhs)
{
    Sales_data sum=lhs;
    sum.combine(rhs);
    return sum;
}
int main(int argc,char **argv)
{
    Sales_data total;
    if(read(cin,total))
     {
         Sales_data trans;
     while(read(cin,trans))
      {
          if(total.bookNo==trans.bookNo)
          {   
              total=add(total,trans);
          }
          else 
          {
              print(cout,total);
              total=trans;
          }

      }
     print(cout,total);
     }
   
    else
    {
        std::cerr<<"No data"<<std::endl;
        return -1;
    }
    return 0;
}