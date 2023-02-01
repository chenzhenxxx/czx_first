//mutable
#include<iostream>
#include<string>

class Entity
{
private:
    std::string m_Name;
    mutable int cnt=0;
public:
    const std::string& GetName() const
    {   
        cnt++;
        return m_Name;
    }
};

int main()
{
    const Entity e;
    int x=8;
    auto f = [=]() mutable
    {   x++;
        std::cout << x << std::endl;
    };
    e.GetName();
}