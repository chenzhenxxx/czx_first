//C++的成员初始化列表
#include <iostream>
#include <string>

class Example
{
 public:
     Example()
     {
        std::cout << "Created Entity!" << std::endl;
     }

     Example(int x)
     {
        std::cout << "Created Entity with " << x << std::endl;
     }
};
class Entity
{
    private:
         std::string m_Name;
         Example m_example;  //初始化一次
    public:
        //  Entity()
        //  {
        //     m_Name = std::string("Unknown");  
        //     m_example = Example(8);  //初始化第二次并赋值给m_example
        //  }
         Entity()
           : m_example(Example(8))  //= m_Example(8)
         {
            m_Name = std::string("Unknown");  
         }

         Entity(const std::string& name)
         {
            m_Name = name;
         }

         const std::string& GetName() const { return m_Name;}
};
int main()
{
    Entity e0;
    std::cout << e0.GetName() << std::endl;

    // Entity e1("czx");
    // std::cout << e1.GetName() << std::endl;
}