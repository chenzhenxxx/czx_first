#include <iostream>
#include <string>

#include <stdlib.h>

int main()
{   using namespace std::string_literals;

    std::u32string name0 = U"Cherno"s + U" hello";
    const char* name = u8"CHerno";
    const wchar_t* name2 = L"czx";
    const char16_t* name3 = u"czx";
    const char32_t* name4 =U"CZX";
    const char* example = R"(Line1
Line2
Line3
Line4)";  //R忽略转义字符
    //name[2] = 'a';  //不能这样，name是一个指针
    
    std::cout << example<< std::endl;
    std::cin.get();    
}