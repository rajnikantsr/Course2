#include<iostream>
using namespace std;
// #define PI 3.14 //Object like macres
// #define print(x) cout << "Value is : " << x //Function like macros
// #define PRINT_RECTANGLE(width, height) \
// for (int i = 0; i < height; i++) { \
//     for (int j = 0; j < width; j++) { \
//         cout << "*"; \
//     } \
//     cout << endl; \
// }
// #define PRINT_TRIANGLE(n) \
// for (int i = 0; i < n; i++) { \
//     for (int j = 0; j <= i; j++) { \
//         cout << "* "; \
//     } \
//     cout << endl; \
// }
// #define PRINT_EQUILATERAL_TRIANGLE(n) \
// for (int i = 0; i < n; i++) { \
//     for (int j = 0; j < n - i - 1; j++) { \
//         cout << " "; \
//     } \
//     for (int k = 0; k < 2 * i + 1; k++) { \
//         cout << "*"; \
//     } \
//     cout << endl; \
// }
//Inline function:::::::::::::::::::
inline int getMax(int a, int b) {
    if(a>b) {
        return a;
    } else {
        return b;
    }
    // return (a>b) ? a : b;
}
//Default argument:::::::::::
void print(int arr[], int size, int start = 0) {
    for(int i = start; i<size; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
int main() {
    // int r;
    // cin >> r;
    // double area = PI * r * r;
    // cout << "Area of circle : " << area << endl;
    // int value = 5;
    // print(value);
    // PRINT_RECTANGLE(4, 3);
    // int n;
    // cout << "Enter the number of rows: ";
    // cin >> n;
    // PRINT_TRIANGLE(n);
    // int n;
    // cout << "Enter the number of rows: ";
    // cin >> n;
    // PRINT_EQUILATERAL_TRIANGLE(n);
    // cout << "This is line no. : " << __LINE__ << " In file " << __FILE__ << " And is declared on date of : " << __DATE__ << " At time : " << __TIME__ << endl;
//Inline functions:::::::::::::::::::::::::::
    int a, b;
    cin >> a >> b;
    int ans = 0;
    ans = getMax(a, b); 
    cout << ans << endl;
    int arr[5] = {1, 4, 5, 6, 9};
    int size = 5;
//Default argument:::::::::::
    print(arr, size);
    print(arr, size, 2);
    return 0;
}