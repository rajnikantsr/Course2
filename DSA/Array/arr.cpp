#include <iostream>
#include <math.h>
using namespace std;

// void printArr(int arr[], int size) {
//         cout << "Printing the array" << endl;
//         for(int i = 0; i < size; i++) {
//             cout << arr[i] << " ";
//         }
//         cout << "Printing DONE" << endl;
//     }
void getMax(int num[], int n) {//Time complexity = O(nlogn)
    int maxi = INT_MIN;
    int secLargest = -1;
    for(int i = 0; i<n; i++) {
        maxi = max(maxi, num[i]);
    }
    for(int i = 0; i<n; i++) {
        if(num[i] > secLargest && num[i] != maxi) {
            secLargest = num[i];
        }
    }
    cout << "Maximum value is : " << maxi << endl;
    cout << "Second Largest value is : " << secLargest << endl;
}
// int getMin(int num[], int n) {
//     int mini = INT_MAX;
//     for(int i = 0; i<n; i++) {
//         //Pre defined keyword
//         mini = min(mini, num[i]);
//         // if(num[i] < mini) {
//         //     mini = num[i];
//         // }
//     }
//     return mini;
// }

// int getSum(int sum[], int n){
//     int ans = 0;
//     for(int i = 0; i<n; i++) {
//         ans = ans + sum[i];
//     }
//     return ans;
// }
// bool search(int arr[], int n, int key) {
//     for(int i = 0; i<n; i++) {
//         if(arr[i] == key) {
//             return 1;
//         }
//     }
//     return 0;
// }
// void revArr(int arr[], int n) {
//     int start = 0;
//     int end = n-1;
//     while(start<=end) {
//         swap(arr[start], arr[end]);
//         start++;
//         end--;
//     }
// }
// void printArr(int arr[], int n) {
//     for(int i = 0; i<n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }
void altArr(int arr[], int n) {
    int i = 0;
    while(i+1 < n) {
        swap(arr[i], arr[i+1]);
        i=i+2;
    }
}
void printAlt(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int secLargest(int arr5[], int n) {//Time complexity = O(n)
    int largest = arr5[0];
    int secLar = -1;
    for(int i = 0; i<n; i++) {
        if(arr5[i] > largest) {
            secLar = largest;
            largest = arr5[i];
        }
        else if(arr5[i] < largest && arr5[i] > secLar) {
            secLar = arr5[i];
        }
    }
    return secLar;
}
int main() {
/*    int first[15];
    printArr(first, 15);*/

/*     int second[10] = {2, 7, 13};
     printArr(second, 10);
     int secondsize = sizeof(second)/sizeof(int);
     cout << "Size of second is : " << secondsize << endl;*/

/*     int third[7] = {2, 7};
     printArr(third, 7);*/
/*    int size;
    cout << "Enter no. for value inputs : ";
    cin >> size;
    //get max/min
    int num[100];
    // taking input in array
    for(int i = 0; i<size; i++) {
        cin >> num[i];
    }
    getMax(num, size);
    cout << endl;*/
//     cout << "Minumum value is : " << getMin(num, size) << endl;
// //get sum of array
//     int n;
//     cout << "Enter value you want to enter : ";
//     cin >> n;
//     cout << "Enter your input's : ";
//     int fourth[100];
//     for(int i = 0; i<n; i++) {
//         cin >> fourth[i];
//     }
//     int sum = getSum(fourth, n);
//     cout << "Sum of all input's : " << sum << endl;
    // int arr[100] = {2, 6, -9, 7, 32, 5, 18, 6};
    // cout << "Enter the element to search for : ";
    // int key; 
    // cin >> key;
    // bool found = search(arr, 100, key);
    // if( found ) {
    //     cout << "Key is present" << endl;
    // } else {
    //     cout << "Key is absent" << endl;
    // }
    // int arr[8] = {2, 6, -9, 7, 32, 5, 18, 6};
    // int brr[5] = {3, -5, 4, 0, 2};
    // revArr(arr, 8);
    // revArr(brr, 5);
    // printArr(arr, 8);
    // printArr(brr, 5);
    // int arr[9] = {2, 3, 4, 5, 6, 7, 8, 9};
    // for(int i = 0; i<8; i++) {
    //     cout << arr[i] << " ";
    // } cout << endl;
    // altArr(arr, 8);
    // printAlt(arr, 8);
    int arr5[5] = {1, 3, 7, 7, 4};
    cout << "Second largest element : " << secLargest(arr5, 5) << endl;
    return 0;
}
