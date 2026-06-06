#include <iostream>

using namespace std;

int main() {
    for (int i = 5; i >= 1; i--) {
        for (int space = 1; space <= 5 - i; space++) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            if (j % 2 != 0) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return 0;
}

// OUTPUT
// 1 0 1 0 1 
//   1 0 1 0 
//     1 0 1 
//       1 0 
//         1 
