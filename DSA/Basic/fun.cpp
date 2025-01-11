// #include<iostream>
// using namespace std;
// // pow(num1, num2) and given no. is odd or even
// // int power(int a, int b) {
//     //     int ans = 1;
//     //     for(int i = 1; i<=b; i++) {
//     //         ans = ans * a;
//     //     }
//     //     return ans;
//     // }
// // int power() {
// //     int a, b;
// //     cout << "Enter 1st no. space 2nd no. : ";
// //     cin >> a >> b;
// //         int ans = 1;
// //         for(int i = 1; i<=b; i++) {
// //             ans = ans * a;
// //         }
// //         return ans;
// // }
// // bool isEven(int a) {
// //     if(a&1) {//Odd
// //         return 0; 
// //     }
// //     return 1;//Even
// // }
// // int factorial(int n) {
// //     int fact = 1;
// //     for(int i = 1; i<=n; i++) {
// //         fact = fact * i;
// //     }
// //     return fact;
// // }
// // int nCr(int n, int r) {
// //     int num = factorial(n);
// //     int den = factorial(r) * factorial(n-r);
// //     return num/den;
// // }
// // void printCounting(int n) {
// //     for(int i=1; i<=n; i++) {
// //         cout << i << "\t";
// //     }
// //     cout << endl;
// // }
// // bool isPrime(int n) {
// //     for(int i=2; i<n; i++) {
// //         if(n%i == 0) {
// //             return 0;
// //         }
// //     }
// //     return 1;
// // }
// // void isPrime(int n) {
// //     for(int i=2; i<n; i++) {
// //         if(n%i == 0) {
// //             cout << "Not prime no." << endl;
// //             break;
// //         } else {
// //             cout << "Prime no." << endl;
// //             break;
// //         }
// //     }
// //     if(n == 1) {
// //         cout << "Co-Prime" << endl;
// //     }
// // }
// //Excessing any term of A.P.
// // void givenTerm(int n) {
// //     int AP = 3 * n + 7;
// //     cout << "nth term of A.P(3*n+7) : " << AP << endl;
// // }
// //Excessing set bits of a and b
// // void setBit(int n, int m) {
// //     int ans1 = 0;
// //     int ans2 = 0;
// //     int i = 0;
// //     while(n!=0) {
// //         int bit1 = n&1;
// //         ans1 = ans1 + bit1;
// //         n = n >> 1;
// //         i++;
// //     }
// //     while(m!=0) {
// //         int bit2 = m&1;
// //         ans2 = ans2 + bit2;
// //         m = m >> 1;
// //         i++;
// //     }
// //     cout << "Ans is : " << ans1 + ans2;

// // }
// // int fibTerm(int n) {
// //     int a = 0, b = 1, nextTerm;
// //     for(int i = 1; i<n; i++) {
// //         nextTerm = a + b;
// //         a = b;
// //         b = nextTerm;
// //     }
// //     return a;
// // }
// int main() {
//     // int num1, num2;
//     // cout << "Enter num1 to the power num2 : ";
//     // cin >> num1 >> num2;
//     // int ans = power(num1, num2);
//     // cout << "num1 ^ num2 : " << ans << endl;
//     // int ans = power();
//     // cout << "1st no. to the power 2nd no. : " << ans << endl;
// //num is odd or even
//     // int num;
//     // cout << "Enter odd/Even no. : ";
//     // cin >> num;
//     // if(isEven(num)) {
//     //     cout << "Number is Even" << endl;
//     // } else {
//     //     cout << "Number is odd" << endl;
//     // }
// //nCr
//     // int n, r;
//     // cout << "Enter n and then r : ";
//     // cin >> n >> r;
//     // cout << "Answer of nCr is : " << nCr(n, r) << endl;
// //natural no.
//     // int n;
//     // cout >> "Enter no. to prnt natural no. : ";
//     // cin >> n;
//     // printCounting(n);
// //prime or not
//     // int n;
//     // cout << "Enter no. to check prime or not : ";
//     // cin >> n;
//     // if(isPrime(n)) {
//     //     cout << "Prime no." << endl;
//     // } else {
//     //     cout << "Not a Prime no." << endl;
//     // }
//     // int n;
//     // cin >> n;
//     // isPrime(n);
//     // int n;
//     // cin >> n;
//     // givenTerm(n);
//     // int n, m;
//     // cin >> n >> m;
//     // setBit(n, m);
//     // int n;
//     // cout << "Enter term of fibonacci series : ";
//     // cin >> n;
//     // cout << "Your term of fibonacci series : " << fibTerm(n);
// return 0;
// }
