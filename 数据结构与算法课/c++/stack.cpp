#include <iostream>
using namespace std;

const int SIZE = 90;

template <class T>
class Stack
{
public:
    Stack() : tos(0) {}
    ~Stack() {}
    void push(T n);
    T pop();
private:
    T stack[SIZE];
    int tos;
};

template <class T>
void Stack<T>::push(T n)
{
    if (tos == SIZE)
    {
        cout << "Stack is full. Cannot push element." << endl;
        return;
    }
    stack[tos++] = n;
}

template <class T>
T Stack<T>::pop()
{
    if (tos == 0)
    {
        cout << "Stack is empty. Cannot pop element." << endl;
        return T();
    }
    return stack[--tos];
}

int main()
{
    Stack<int> intStack;
    intStack.push(5);
    intStack.push(10);
    intStack.push(15);

    cout << "Popped value: " << intStack.pop() << endl;
    cout << "Popped value: " << intStack.pop() << endl;

    Stack<char> charStack;
    charStack.push('a');
    charStack.push('b');
    charStack.push('c');

    cout << "Popped character: " << charStack.pop() << endl;

    Stack<float> floatStack;
    floatStack.push(1.1f);
    floatStack.push(2.2f);
    floatStack.push(3.3f);

    cout << "Popped value: " << floatStack.pop() << endl;

    return 0;
}