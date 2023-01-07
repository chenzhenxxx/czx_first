#include<iostream>

// void Function()
// {
//     static int i = 0;
//     i++;
//     std::cout<<i<<std::endl;
// }

// int main()
// {   
//     for(int j=1;j<=5;j++)
//      Function();
//     std::cin.get();
// }


class Singleton
{
private:
     static Singleton* s_Instance;
public:
    static Singleton& Get() {return *s_Instance;}

    void Hello() {std::cout<<"hello"<<std::endl;}
};

Singleton*Singleton::s_Instance=nullptr;


int main()
{
    Singleton::Get().Hello();
}
