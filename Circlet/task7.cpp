#include <iostream>

using namespace std;

int main() {
    for (int r = 1; r <= 5; r++) {
        for (int c = 1; c <= 5; c++) {
            if (c == 1 || r == 1 || r == 3 || (r == 2 && c == 5)) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}

// OUTPUT
// * * * * * 
// *       * 
// * * * * * 
// *         
// *         