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

    int rowNum;
    std::cout << "\nEnter row number: ";
    std::cin >> rowNum;

    if (rowNum < 0 || rowNum >= rows) {
        std::cout << "Invalid row number." << std::endl;
    } else {
        std::cout << "Elements of row " << rowNum << ": ";
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            std::cout << a[rowNum][j];
            if (j < cols - 1) {
                std::cout << ", ";
            }
            rowSum += a[rowNum][j];
        }
        std::cout << "\nThe sum of a row " << rowNum << ": " << rowSum << std::endl;
    }

    std::cout << std::endl;

    int colNum;
    std::cout << "Enter column number: ";
    std::cin >> colNum;

    if (colNum < 0 || colNum >= cols) {
        std::cout << "Invalid column number." << std::endl;
    } else {
        std::cout << "Elements of column " << colNum << ": ";
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            std::cout << a[i][colNum];
            if (i < rows - 1) {
                std::cout << ", ";
            }
            colSum += a[i][colNum];
        }
        std::cout << "\nThe sum of column " << colNum << ": " << colSum << std::endl;
    }

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
// Enter row number: 0
// Elements of row 0: 2, 7, 1
// The sum of a row 0: 10

// Enter column number: 2
// Elements of column 2: 1, 6, 8
// The sum of column 2: 15