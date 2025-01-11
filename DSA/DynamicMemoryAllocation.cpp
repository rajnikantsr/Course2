#include<iostream>
using namespace std;
void update(int n) {
    n++;
}
void update2(int &n) {
    n++;
}
int& func(int& n) {
    int num = n;
    int &ans = num;
    return ans;
}
int* fun(int n) {   
    int *ptr = &n;
    return ptr;
}
int getSum(int *arr, int n) {
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += arr[i];
    }
    return sum;
}
int main() {
    // int i = 4;
    // int& j = i;// Creating a reference operator
    // cout << "Value of i : " << i << endl;
    // i++;
    // cout << "Value of i : " << i << endl;
    // j++;
    // cout << "Value of i : " << i << endl;
    int n;
    cin >> n;
    // update(n);
    // cout << "Pass by value : " << n << endl;
    // update2(n);
    // cout << "Pass by reference : "<< n << endl;
    // func(n);
    // fun(n);
    // int *arr = new int[n];
    // for(int i = 0; i<n; i++) {
    //     cin >> arr[i];
    // }
    // cout << "Sum of value : " << getSum(arr, n) << endl;
    while(true) {
        int *var = new int;    
    }
    return 0;
}