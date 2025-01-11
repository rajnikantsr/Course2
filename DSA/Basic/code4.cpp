#include<iostream>
#include<math.h>
using namespace std;

int main() {
// //     int n;
// //     cout << "Enter no. : ";
// //     cin >> n;
// // //convert no. in binary
// //     int ans = 0;
// //     int i = 0;
// //     while(n != 0) {
// //         int bit = n & 1;
// //         ans = (bit * pow(10, i)) + ans;
// //         n = n>>1;
// //         i++;
// //     }
// //     cout << ans << endl;

//printing -ve no. to binary

    int n;
    cout << "Enter the decimal number: ";
    cin >> n;
    int ans = 0;
    int i = 0;
    if(n < 0) {
        n = -1 * n;
    }
    while (n != 0)
    {
        int bit = n & 1; //reads last bit
        ans = ans + (bit * pow(10, i));
        n = n >> 1; //helps to read the other bits by shifting it to the right
        i++; 
    }
    cout<< "Binary equivalent: " << (((~(ans) ^ 1) * -1));
//printing binary to decimal
    // int n;
    // cout << "Enter binary no. : ";
    // cin >> n;
    // int i = 0, ans = 0;
    // while(n!=0) {
    //     int digit = n%10;
    //     if(digit == 1) {
    //         ans = ans + pow(2, i);
    //     }
    //     n = n/10;
    //     i++;
    // }
    // cout << ans << endl;
//SWITCH
//     int num;
//     cout << "Choose no. from 1,2 : ";
//     cin >> num;
//     char ch = '1';
//     char ch1 = 'R'; 
//     cout << endl;
//     while(1) {
//     switch(num) {
//         case 1 : cout << "Hello" << endl;
//             break;
//         case 2 : switch(ch) {//Switch inside switch
//             case '1' : cout << ch1 << endl;
//         }
//             break;
//         default : cout << "Default case" << endl;
//     }
//     exit(0);//Exit from loop
// }
//     cout << endl;
//Calculator
    // float a, b;
    // cout << "Enter value of a : ";
    // cin >> a;
    // cout << "Enter value of b : ";
    // cin >> b;
    // char op;
    // cout << "Enter the operation you want to perform : ";
    // cin >> op;
    // switch( op ) {
    //     case '+' : cout << (a+b) << endl;
    //             break;
    //     case '-' : cout << (a-b) << endl;
    //             break;
    //     case '*' : cout << (a*b) << endl;
    //             break;
    //     case '/' : cout << (a/b) << endl;
    //             break;
    //     case '^' : cout << pow(a, 2) << endl << pow(b, 2) << endl; 
    //     default : "Enter the valid operation";
    // }
//Distribution of money of 100, 20, 1 rs. to cost
    // int amount;
    // cout << "Enter total amount : ";
    // cin >> amount;
    // int moneyVal;
    // cout << "Enter money value : ";
    // cin >> moneyVal;
    // int a, a1, b, b1, c, c1;
    // a = amount/100;
    // a1 = amount%100;
    // b = a1/20;
    // b1 = a1%20;
    // c = b1/1;
    // switch(moneyVal) {
    //     case 100 : cout << "100 Rs. note : " << a << endl;
    //         break;
    //     case 20 : cout << "50 Rs. note : " << b << endl;
    //         break;
    //     case 1 : cout << "1 Rs. note : " << c << endl;
    //     default : cout << "You entered the incorrect money value";
    //         break;
    // }
}