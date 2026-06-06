#include <iostream>

int main() {
    int size;
    std::cout << "Enter the array's size: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Invalid array size." << std::endl;
        return 1;
    }

    int* a = new int[size];
    std::cout << "Enter array's elements:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "a[" << i << "] = ";
        std::cin >> a[i];
    }

    std::cout << "Negative elements from an Array: ";
    bool first = true;
    for (int i = 0; i < size; i++) {
        if (a[i] < 0) {
            if (!first) {
                std::cout << ", ";
            }
            std::cout << a[i];
            first = false;
        }
    }
    std::cout << std::endl;

    delete[] a;
    return 0;
}

// Input Data:
// 5
// 2
// -4
// 1
// -3
// -5

// Output:
// Negative elements from an Array: -4, -3, -5