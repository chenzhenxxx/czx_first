// C++隐式转换与explicit关键字

#include <string>
#include <iostream>

class Entity
{
private:
     std::string m_Name;
     int m_Age;
public:
     explicit Entity(const std::string& name)  //explict禁止隐式转换
     : m_Name(name), m_Age(-1) {}
     explicit Entity(int age)
     : m_Name("Unknown"), m_Age(age) {}

};

void PrintEntity(const Entity& entity)
{
    //
}
int main()
{    PrintEntity(Entity(22));
    //PrintEntity(22); //从 int 隐式转换为 Entity
    //PrintEntity("czx"); //不行 只能转换一次 从const char * 变成std::string 再变成 Entity,两次了
    // PrintEntity(std::string("CZX"));
    PrintEntity(Entity("CZX"));
    std::cin.get();
}
