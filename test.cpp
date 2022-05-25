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
int s=1;
class num
{
    public: num(){val=1;}
     num(const num &m )
     {
         val=s++;
     }
     int val=1;
};
void f(num s)
{
    cout<<s.val<<endl;
}
int main()
{
    num t1,t2=t1,t3=t2;
    f(t1);f(t2);f(t3);
    return 0;
}