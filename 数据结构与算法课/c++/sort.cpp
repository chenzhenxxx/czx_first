#include <iostream>

template<typename T>
void selectionSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    // Integer array
    int intArray[] = {5, 2, 9, 1, 3};
    int intSize = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Before sorting (intArray): ";
    for (int i = 0; i < intSize; i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    selectionSort(intArray, intSize);

    std::cout << "After sorting (intArray): ";
    for (int i = 0; i < intSize; i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Double array
    double doubleArray[] = {3.14, 1.23, 2.71, 0.99, 4.56};
    int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Before sorting (doubleArray): ";
    for (int i = 0; i < doubleSize; i++) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;

    selectionSort(doubleArray, doubleSize);

    std::cout << "After sorting (doubleArray): ";
    for (int i = 0; i < doubleSize; i++) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}