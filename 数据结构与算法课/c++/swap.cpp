
#include <iostream>
using namespace std;
template<typename T>
void swapVariables(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    // Normal Inputs and Outputs
    int num1 = 5, num2 = 10;
    std::cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;
    swapVariables(num1, num2);
    std::cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;

    char char1 = 'A', char2 = 'B';
    std::cout << "Before swap: char1 = " << char1 << ", char2 = " << char2 << std::endl;
    swapVariables(char1, char2);
    std::cout << "After swap: char1 = " << char1 << ", char2 = " << char2 << std::endl;

    double double1 = 3.14, double2 = 6.28;
    std::cout << "Before swap: double1 = " << double1 << ", double2 = " << double2 << std::endl;
    swapVariables(double1, double2);
    std::cout << "After swap: double1 = " << double1 << ", double2 = " << double2 << std::endl;

    // Exception Inputs and Outputs
    bool bool1 = true;
    int int1 = 20;
    std::cout << "Before swap: bool1 = " << bool1 << ", int1 = " << int1 << std::endl;
    swapVariables(bool1, int1); // An exception occurs when trying to swap variables of different types
    std::cout << "After swap: bool1 = " << bool1 << ", int1 = " << int1 << std::endl;

    return 0;
}
