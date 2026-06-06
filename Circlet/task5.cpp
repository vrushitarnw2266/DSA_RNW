#include <iostream>

using namespace std;

int main() {
    for (int i = 5; i >= 1; i--) {
        for (int space = 1; space <= i - 1; space++) {
            cout << "  ";
        }
        for (int j = i; j <= 5; j++) {
            cout << j << " ";
        }
        for (int j = 4; j >= i; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

// OUTPUT
//         5 
//       4 5 4 
//     3 4 5 4 3 
//   2 3 4 5 4 3 2 
// 1 2 3 4 5 4 3 2 1 
