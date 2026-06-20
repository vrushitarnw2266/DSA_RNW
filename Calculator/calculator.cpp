#include <iostream>

using namespace std;

// User Defined Functions (UDF) for basic arithmetic operations

// Function to perform addition
int add(int a, int b) {
    return a + b;
}

// Function to perform subtraction
int subtract(int a, int b) {
    return a - b;
}

// Function to perform multiplication
int multiply(int a, int b) {
    return a * b;
}

// Function to perform division
int divide(int a, int b) {
    if (b == 0) {
        cout << "Error: Division by zero is not allowed." << endl;
        return 0;
    }
    return a / b;
}

// Function to perform modulus
int modulo(int a, int b) {
    if (b == 0) {
        cout << "Error: Modulus by zero is not allowed." << endl;
        return 0;
    }
    return a % b;
}

int main() {
    int choice;
    
    // Looping construct to run the program continuously until exit choice is selected
    while (true) {
        // Displaying the menu
        cout << "Press 1 for +" << endl;
        cout << "Press 2 for -" << endl;
        cout << "Press 3 for *" << endl;
        cout << "Press 4 for /" << endl;
        cout << "Press 5 for %" << endl;
        cout << "Press 0 for the exit" << endl;
        
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        // Check if the user wants to exit
        if (choice == 0) {
            break;
        }
        
        // Handle invalid choices outside the menu options
        if (choice < 1 || choice > 5) {
            cout << "Invalid choice! Please try again.\n" << endl;
            continue;
        }
        
        int num1, num2;
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        
        // Switch case to select the correct UDF based on user choice
        switch (choice) {
            case 1:
                cout << "Addition of " << num1 << " and " << num2 << " is " << add(num1, num2) << endl;
                break;
            case 2:
                cout << "Subtraction of " << num1 << " and " << num2 << " is " << subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Multiplication of " << num1 << " and " << num2 << " is " << multiply(num1, num2) << endl;
                break;
            case 4:
                cout << "Division of " << num1 << " and " << num2 << " is " << divide(num1, num2) << endl;
                break;
            case 5:
                cout << "Modulo of " << num1 << " and " << num2 << " is " << modulo(num1, num2) << endl;
                break;
        }
        cout << endl; // Blank line for formatting
    }
    
    return 0;
}
