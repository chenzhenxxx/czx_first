#include <iostream>


bool isPowerOfFour(int n){
    if(n <= 0) {
        return false;                          // (1)
    }
    int x = (int)(log2(n) / log2(4) + 1e-8);   // (2)
    return fabs(n - pow(4, x)) < 1e-8;         // (3)
}


#define Main int main() \
{\
   std::cout << "hei " << std::endl;\
}
Main
