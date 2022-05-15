#include<iostream>
using namespace std;
int main()
{   int x=1;
    auto f=[](int a,int b){return a+b;};
    cout<<f(3,2);
    auto g=[x](int s){return x+s;};
    cout<<g(1);
}