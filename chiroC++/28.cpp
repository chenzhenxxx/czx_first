#include<iostream>
 #include<string>

 class Entity
 {
public:
    virtual std::string GetName() { return "Entity"; }
 } ;

 class Player : public Entity
 {
 private:
      std::string m_Name;
 public:
     Player(const std::string &name)
     : m_Name(name) {}
    
     std::string GetName() override { return m_Name; }
 
 };

void PrintName(Entity* e)
{
    std::cout << e->GetName() << std::endl;
}
 int main()
 {
    Entity* e = new Entity();
    PrintName(e);

    Player* p = new Player("Czx");
    PrintName(p);

    std::cin.get();
 }