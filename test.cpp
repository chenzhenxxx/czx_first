#include<iostream>  
#include<string>  
#include<fstream>
#include<list>
#include<vector> 
#include<map>  
#include<set>
#include<cctype>//ctype无法打开，包含tolower()函数和ispunct函数
#include<algorithm>
#include<utility>//保存pair的头文件
#include<memory>
using namespace std;
int main()
{   char p[20]="hello";
    string a(p,12);
    cout<<a;

}