//C++智能指针
#include <iostream>
#include <string>
#include <memory>

//unique_ptr 没有内存消耗
//shared_ptr 要额外开辟引用计数的内存块
//weak_ptr 当将shared_ptr赋值给它时，不会增加引用计数
//优先unipque_ptr,再shared_ptr
class Entity
{
public:
    Entity()
    {
        std ::cout << "Created Entity!" << std::endl;
    }
    ~Entity()
    {
        std ::cout << "Destoryed Entity!" << std::endl;
    }
    void Print() {}
};

int main()
{
  {
    std::unique_ptr<Entity> entity = std::make_unique<Entity>();
    std::shared_ptr<Entity> shareEntity = std::make_shared<Entity>();
    entity->Print();
  }
    std::cin.get();
}