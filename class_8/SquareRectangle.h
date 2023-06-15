#include<iostream>
#include<math.h>
class Square
{
protected:
int edge;
public:
virtual double GetArea();
Square(int edg);
~Square( )
{ }
};
Square::Square(int edg)
{ edge=edg; }
//求正方形的面积
double Square::GetArea()
{
double result;
result=edge*edge;
return result;
}
//下面的全局函数是专门为了调用虚函数实现运行时的多态性而设计的。
double objGetArea(Square* base);
class Rectangle:public Square
{
protected:
int length;
//它的宽由正方形类 Square 的成员提供
public:
double GetArea();
Rectangle(int edg,int leng);
~Rectangle(){ }
};
double Rectangle::GetArea()//求矩形的面积
{
double result;
result=length*edge;
return result;
}
Rectangle::Rectangle(int edg,int leng):Square(edg)
{
//调用基类的构造函数 Square(edg)使 edge=edg;
length=leng;
}
double objGetArea(Square* obj)
{
return obj->GetArea();
}