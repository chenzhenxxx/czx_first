//C++ new关键字

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
   int a = 2;
   int* b = new int[50];

   Entity*e = new Entity(); // = Entity* e = (Entity*)malloc(sizeof(Entity));
   
   delete e;
   delete[] b;
   std::cin.get();
}