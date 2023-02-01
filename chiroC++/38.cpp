//创建并初始化C++对象

#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
     String m_Name;
public:
     Entity() : m_Name("Unknown") {}
     Entity(const String& name) :m_Name(name) {} 

     const String& GetName() const {return m_Name;}
};

int main()
{
    Entity* e;
    {
        // Entity entity("Cherno"); 在栈上
        Entity* entity = new Entity("CZX"); //在堆上
        e = entity;
        std::cout << entity->GetName() << std::endl;

    }

    delete e;
}