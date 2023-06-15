#include<iostream>
#include<math.h>
#include"SquareRectangle.h"
using namespace std;
int main()
{
Square Squa1(100); //调用 Square::Square(int)初始化
Rectangle Rect(200,300);//调用 Rectangle::Rectangle(int,int)初始化
//比较下面两个语句
cout<<"正方形 Squa1(100)的面积为："<<Squa1.GetArea()<<endl;
//静态联编，输出为：10000
cout<<"正方形 Squa1(100)的面积为："<<objGetArea(&Squa1)<<endl;
//比较下面两个语句
cout<<"矩形 Rect(200,300) 的面积为：:"<<Rect.GetArea()<<endl;
//静态联编，输出为 60000
cout<<"矩形 Rect(200,300) 的面积为：:"<<objGetArea(&Rect)<<endl;
//动态联编，输出为 60000
return 0;
}