#include <iostream>
using namespace std;
void Reverselist(int *arry, int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int tmp = arry[i];
        arry[i] = arry[size - i - 1];
        arry[size - i - 1] = tmp;
    }
}
void Print(int *arry, int size)
{
    for (int i = 0; i < size; i++)
        cout << arry[i] << " ";
    cout << endl;
}
int main()
{
    int size;
    printf("请输入数组个数！");
    cin >> size;
    int arry[size + 1];
    for (int i = 0; i < size; i++)
        cin >> arry[i];
    Print(arry, size);
    Reverselist(arry, size);
    Print(arry, size);
}