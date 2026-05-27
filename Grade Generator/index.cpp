#include <iostream>
using namespace std;

int main() {

    int marks;
    char grade;

    cout << "Enter your marks: ";
    cin >> marks;

    if (marks >= 90 && marks <= 100) {
        grade = 'A';
    }
    else if (marks >= 80) {
        grade = 'B';
    }
    else if (marks >= 70) {
        grade = 'C';
    }
    else if (marks >= 60) {
        grade = 'D';
    }
    else if (marks >= 35) {
        grade = 'E';
    }
    else {
        grade = 'F';
    }

  
    cout << "Your Grade is: " << grade << endl;

 
    switch(grade) {

        case 'A':
            cout << "Excellent Performance";
            break;

        case 'B':
            cout << "Very Good";
            break;

        case 'C':
            cout << "Good";
            break;

        case 'D':
            cout << "Average";
            break;

        case 'E':
            cout << "Need Improvement";
            break;

        case 'F':
            cout << "Fail";
            break;

        default:
            cout << "Invalid Marks";
    }

  
    if (marks >= 35) {
        cout << "\nEligible for Next Level";
    }
    else {
        cout << "\nNot Eligible for Next Level";
    }

    return 0;
}