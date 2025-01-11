#include<iostream>
using namespace std;

int main() {
// //Use of Bitwise operator
//     int a=8;
//     int b=5;
//     cout << "a&b : " << (a&b) << endl;
//     cout << "a|b : " << (a|b) << endl;
//     cout << "~a : " << (~a) << endl;
//     cout << "a^b : " << (a^b) << endl; 

// //Use of Left or Right shift operator
//     cout << (17>>1) << endl;
//     cout << (17>>2) << endl;
//     cout << (19<<1) << endl;
//     cout << (21<<2) << endl;

// //Use of increment, decr. operator
//     int i = 7;
//     cout << (++i) << endl; //i=8, i=8
//     cout << (i++) << endl; //i=8, i=9
//     cout << (--i) << endl; //i=8, i=8
//     cout << (i--) << endl; //i=8, i=7
// int a, b=1;
// a=10;
// if(++a) {
//     cout << b;
// } else {
//     cout << ++b;
// }
// int a=1;
// int b=2;
// if(a-- > 0 ||  ++b > 2) {//Quest 2 = &&
//     cout << "Stage 1 - Inside If";
// } else {
//     cout << "Stage 2 - Inside Else";
// }
// cout << a << " " << b << endl;
//Use of FOR loop
// int a;//method1
// cout << "Enter any no. : ";
// cin >> a;
// cout << "Printing natural no's. :- " << endl;
// for(int i = 1; i<=a; i++) {
//     cout << i << "\t";
// }
// int i = 1;//method2
// for( ; ; ) {
//     if(i<=a) {
//         cout << i << "\t";
//     }
//     else {
//         break;
//     }
//     i++;
// }
// for(int a = 0, b = 1, c = 2; a>=0 && b>=0 && c>=0; a--, b--, c--) {
//     cout << a << " " << b << " " << c;
// }
int n;//print natural no's sum
cout << "Enter any no. : ";
cin >> n;
cout << "Printing natural no's. sum:- " << endl;
int sum = 1;
for(int i = 1; i<=n; i++) {
    sum*=i;
    // cout << sum << endl;//add no. and shift to next value
}
cout << sum << endl;//print only sum of natural no.
// int n;//print fibonacchi series
// cin >> n;
// int a = 0;
// int b = 1;
// cout << a << " " << b << " ";
// for(int i = 0; i<=n; i++) {
//     int nextNumber = a + b;
//     cout << nextNumber << " ";
//     a=b;
//     b=nextNumber;
// }
// int n;//checking prime number
// cin >> n;
// bool isPrime = 1;
// for(int i = 2; i<n; i++) {
//     if(n % i ==0) {
//         isPrime = 0;
//         break;
//     } 
// }
// if(isPrime == 0) {
//     cout << "Not a prime no.";
// } else {
//     cout << "A prime no. ";
// }
//Use of continue
// for(int i=0; i<=5; i++) {
//     cout << "Hii" << endl;
//     cout << "Hey" << endl;
//     continue;
//     cout << "Reply?" << endl;
// }
// for(int i = 0; i<=15; i+=2) {
//     cout << i << " ";
//     if(i&1) {
//         continue;
//     }
//     i++;
// }
//homework quest
// for(int i = 0; i<=5; i++) {
//     cout << i << " ";
//     i++;
// }
// for(int i = 0; i<5; i++) {
//     for(int j = i; j<=5; j++) {
//         if(i+j==10) {
//             break;
//         }
//         cout << i << " " << j << endl;
//     }
// }

}
