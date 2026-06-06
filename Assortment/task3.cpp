#include <iostream>

int main() {
    int n;
    std::cout << "Enter the array's row & column size: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid matrix size." << std::endl;
        return 1;
    }

    // Dynamically allocate square matrix
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    std::cout << "Enter array's elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "a[" << i << "][" << j << "] = ";
            std::cin >> a[i][j];
        }
    }

    std::cout << "The transpose matrix of an array:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << a[j][i] << " ";
        }
        std::cout << "\n";
    }

    // Clean up memory
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}

// Input Data:
// 3
// 2
// 4
// 1
// 3
// 5
// 6
// 8
// 2
// 4
// 6

// Output:
// The transpose matrix of an array:
// 2 3 8 
// 4 5 2 
// 1 4 6 
