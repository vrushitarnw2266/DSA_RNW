//For Loop

#include <iostream>
using namespace std;

// int main(){
//     for(int i = 1; i <= 5; i++){
//         cout << i << endl;
//     }
//     return 0;
// }


//While Loop

// #include <iostream>
// using namespace std;

// int main(){
//     int i = 1;
//     while(i <=5){
//         cout << i <<endl;
//         i++;
//     }
//     return 0;
// }

//Do-While Loop

// #include <iostream>
// using namespace std;

// int main(){
//     int i = 1;
//     do{
//         cout << i << endl;
//         i++;
//     } while(i <= 5);
//     return 0;
// }

//Output:
//1 
//2
//3
//4
//5

//Alphabet Skipper

#include <iostream>
using namespace std;

int main() {

    char ch;

    for(ch = 'a'; ch <= 'z'; ch = ch + 2) {
        cout << ch << " ";
    }

    return 0;
}
