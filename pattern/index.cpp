#include <iostream>
using namespace std;

int main() {
    int i, j;

    for (i = 5; i >= 1; i--) {
        for (j = 5; j >= i; j--) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}

// OUTPUT
//  *
//  **
//  ***
//  ****
//  *****

// REVERSE

// int main() {
//     int a, b;

//     for (a = 5; a >= 1; a--) {
//         for (b = 1; b <= a; b ++) {
//             cout << "*";
//         }
//         cout << endl;
//     }

//     return 0;
// }
// OUTPUT
// *****
// ****
// ***
// **
// *

// int main(){
//     int c,d,e;
//    for(c = 1; c <= 5; c++){
//        for(d = 1; d <= 5 - c; d++){
//            cout << " ";
//        }
//        for(e = 1; e <= c; e++){
//            cout << "*";
//        }
//        cout << endl;
//    }

// }

// OUTPUT
//     *
//    **
//   ***
//  ****
// *****

// int main(){
//     int c,d,e;
//    for(c = 5; c >= 1; c--){
//        for(d = 1; d <= 5 - c; d++){
//            cout << " ";
//        }
//        for(e = 1; e <= c; e++){
//            cout << "*";
//        }
//        cout << endl;
//    }

// }

// OUTPUT
// *****
//  ****
//   ***
//    **
//     *

// int main(){
//     int a,b;
//     int num =  1;
//     for(a = 1; a <=4; a++){
//         for(b = 1; b <= a; b++){
//             cout << num << " ";
//             num++;
//         }
//         cout << endl;
//     }
// }

// OUTPUT
// 1
// 2 3
// 4 5 6
// 7 8 9 10

// int main(){
//     int a,b;
//     for(a=1; a<=5; a++){
//         for(b=1; b<=5; b++){
//             cout << a << " ";
//         }
//         cout << endl;
//     }
// }

// OUTPUT
// 1 1 1 1 1
// 2 2 2 2 2
// 3 3 3 3 3
// 4 4 4 4 4
// 5 5 5 5 5

// int main()
// {
//     int a, b;
//     for (a = 1; a <= 5; a++)
//     {
//         for (b = 1; b <= 5 - a; b++){
//             cout << " ";
//         }
//          for(b = 1; b <= a; b++){
//         cout  <<  "* ";
//    }
//      cout << endl;
//     }
//   }

// OUTPUT
//      *
//     * *
//    * * *
//   * * * *
//  * * * * *




