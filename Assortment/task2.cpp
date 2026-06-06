#include <iostream>

int main() {
    int rows, cols;
    std::cout << "Enter the array's row size: ";
    std::cin >> rows;
    std::cout << "Enter the array's column size: ";
    std::cin >> cols;

    if (rows <= 0 || cols <= 0) {
        std::cout << "Invalid row or column size." << std::endl;
        return 1;
    }

    // Dynamically allocate a 2D array
    int** a = new int*[rows];
    for (int i = 0; i < rows; i++) {
        a[i] = new int[cols];
    }

    std::cout << "Enter array's elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "a[" << i << "][" << j << "] = ";
            std::cin >> a[i][j];
        }
    }

    int largest = a[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (a[i][j] > largest) {
                largest = a[i][j];
            }
        }
    }

    std::cout << "The largest element is: " << largest << std::endl;

    // Clean up memory
    for (int i = 0; i < rows; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}


// Input Data:
// 3
// 3
// 2
// 7
// 1
// 3
// 5
// 6
// 9
// 4
// 8

// Output:
// The largest element is: 9