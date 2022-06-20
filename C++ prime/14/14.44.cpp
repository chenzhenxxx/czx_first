#include<functional>
#include<iostream>
#include<map>
using namespace std;
int add(int i,int j)
{
    return i+j;
}
auto mod= [](int i,int j){ return i%j;};
struct divide{
    int operator()(int denominator,int divisor){
        return denominator/divisor;
    }
};
int main()
{
  map<string,function<int(int,int)>>binops={
      {"+",add},
      {"-",std::minus<int>()},
      {"/",divide()},
      {"*",[](int i,int j) {return i*j;}},
      {"%",mod},
          
  };
  cout<<binops["+"](10,5)<<'\n';
  cout<<binops["-"](10,5)<<'\n';
  cout<<binops["*"](10,5)<<'\n';
  cout<<binops["/"](10,5)<<'\n';
  cout<<binops["%"](10,5)<<'\n';
}