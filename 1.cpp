#include "iostream"
using namespace std;

int main()

{
  // Read two integers

    cout << "Enter two integers: ";

  int number1, number2;

  cin >> number1 >> number2;

  try
  {
    if (number2 == 0)
      throw number1;

    cout << number1 << " / " << number2 << " is "
      << (number1 / number2) << endl;

    cout << "C" << endl;
  }
  catch (int e)
  {
    cout << "A" ;
  }

  cout << "B" << endl;

  return 0;
}