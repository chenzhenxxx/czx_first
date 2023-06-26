#include <iostream>
using namespace std;
template <class T> T min(T a, T b)
{
return (a<b)?a:b;
}
int main( )
{
double dobj1=1.1, dobj2=2.2;
char cobj1='c', cobj2='W';
int i=12,j= 68;
cout<<min(i, cobj1 )<<endl; //隐实例化
cout<<min(dobj1, dobj2 )<<endl; //隐式实例化
cout<<min(cobj2, j )<<endl; //隐式实例化
return 0;
}