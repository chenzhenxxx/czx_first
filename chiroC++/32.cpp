//string
#include <iostream>
#include <string>

 void PrintString(const std::string& string)
 {
    std:: cout << string << std::endl;
 }

 int main()
 {
    std::string name = std::string("Czx") + "hello!";
    PrintString(name);
    bool ans = name.find("zx") != std::string::npos;
    std::cout <<name <<std::endl;

    std::cin.get();
  }