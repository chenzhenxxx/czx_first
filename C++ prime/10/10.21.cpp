#include<iostream>
using namespace std;
int main()
{
    int x=5;
    auto f=[x]()mutable->bool{
        if(x!=0)
        {x--;
         return -1;
        }
        else
        {
            return 0;
        }
    };
    while(f()!=0)
    {
      cout<<"h"<<endl;
    }
}