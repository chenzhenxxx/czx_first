//C++ 可见性

//private  只有自己的类有可见性
//protected 自己和自己的子类有可见性
//public    都有可见性 
#include<iostream>
#include<string>

class Entity
 {   
    //private:
    protected:
    int X,Y;
    void Print() {}
public:
    Entity()
    {
        X = 0;
    }


};

class Player : public Entity
{
    Player()
    {
        X = 2;
        Print();
    }
};

int main()
{   Entity e;
    //e.Print();
    // e.X = 2;
    std::cin.get();
}