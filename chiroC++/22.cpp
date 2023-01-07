#include<iostream>

struct Entity
{
    static int x, y;

    static void Print()
{
    std::cout << x << ", " << y <<std::endl;

}
};

int Entity::x;
int Entity::y;

int main()
{
    Entity e;
    e.x=2; //Entity::x=2
    e.y=3; //Entity::y=3
    Entity e1;
    e1.x=3; //Entity::x=3
    e1.y=2; //Entity::y=2
    e.Print(); // Entity::Print()
    e1.Print(); // Entity::Print()

}