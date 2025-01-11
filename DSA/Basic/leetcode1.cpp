// #include<iostream>
// #include<math.h>
// using namespace std;

// int main() {
// // //Ques 1
// // //     int n;
// // //     cout << "Enter no. : ";
// // //     cin >> n;
// // //     int prod = 1;
// // //     int sum = 0;
// // //     while(n != 0) {
// // //         int digit = n % 10;
// // //         prod = prod * digit;
// // //         sum = sum + digit;

// // //         n = n/10;
// // //     }
// // //     int answer = prod - sum;
// // //     cout << "answer (prod - sum) = " << answer;
// // // }
// // //Quest 2
// // int n;
// // cout << "Enter no. : ";
// // cin >> n;
// // int count = 0;
// // while(n != 0) {
// //     if(n&1) {
// //         count++;
// //     }
// //     n = n >> 1;
// // } 
// // cout << count;
// //printing reverse of a number
//     // int n;
//     // cout << "Enter no. : ";
//     // cin >> n;
//     // int ans = 0;
//     // while(n!=0) {
//     //     int digit = n%10;
//     //     if((ans > INT_MAX/10) || (ans < INT_MIN/10)) {
//     //         return 0;
//     //     }
//     //     ans = (ans*10) + digit;
//     //     n = n/10;
//     // }
//     // cout << ans << endl; 
// //complement of base 10
//     // int n;
//     // cout << "Enter no. : ";
//     // cin >> n;
//     // int m = n;
//     // int mask = 0;
//     // if(m==0) {
//     //     cout << "1" << endl;
//     // }
//     // while(m!=0) {
//     //     mask = (mask<<1) | 1;
//     //     m = m>>1;
//     // }
//     // int ans = (~n) & mask;
//     // cout << ans << endl;
// //No. is divisible of pow(2, i)
//     // int n;
//     // cout << "Enter no. : ";
//     // cin >> n;
//     // int ans = 1;
//     // for(int i=0; i<=30; i++) {
//     //     // int ans = pow(2, i);
//     //     // if(ans == n) {
//     //     //     cout << "True" << endl;
//     //     //     break;
//     //     // } 
//     //     if(ans == n) {
//     //         cout << "True" << endl;
//     //     }
//     //     if(ans < INT_MAX) {
//     //         ans = ans * 2;
//     //     }
//     // }
// }
#include<iostream>
#include<vector>
using namespace std;

// int uniqueEle(int arr[], int size) {
//     int ans = 0;
//     for(int i = 0; i<size; i++) {
//         ans = ans ^ arr[i];
//     }
//     return ans;
// }
// int uniqueOcc(int arr[], int n) {
//     int a, b, c, d, e, f, g, h, i, j;
//     int a1 = 0, b1 = 0, c1 = 0, d1 = 0, e1 = 0, f1 = 0, g1 = 0, h1 = 0, i1 = 0, j1 = 0;
//     for(int i = 0; i<n; i++) {
//         if(arr[i] == 0) {
//             a1++;
//         }
//         else if(arr[i] == 1) {
//             b1++;
//         }
//         else if(arr[i] == 2) {
//             c1++;
//         }
//         else if(arr[i] == 3) {
//             d1++;
//         }
//         else if(arr[i] == 4) {
//             e1++;
//         }
//         else if(arr[i] == 5) {
//             f1++;
//         }
//         else if(arr[i] == 6) {
//             g1++;
//         }
//         else if(arr[i] == 7) {
//             h1++;
//         }
//         else if(arr[i] == 8) {
//             i1++;
//         }
//         else if(arr[i] == 9) {
//             j1++;
//         }
//     }
//     cout << a1 << endl << b1 << c1 << d1 << e1 << f1 << g1 << h1 << i1 << j1;
//     if(a1 == b1 && b1 == c1 && c1 == d1 && d1 == e1 && e1 == f1 && f1 == g1 && g1 == h1 && h1 == i1 && i1 == j1 && j1 == a1) {
//         cout << "True" << endl;
//     } else {
//         cout << "False" << endl;
//     }
// }
// //Duplicate in array
// int findDuplicate(int arr[], int size) {
//     int ans = 0;
//     // XOR ing all element in array
//     for(int i = 0; i<size; i++) {
//         ans = ans ^ arr[i];
//     }
// //XOR [1, n-1]
//     for(int i = 1; i< size; i++) {
//         ans = ans^i;
//     }
//     return ans;
// }
// void findDoublet(int arr[], int size) {
//     for(int i = 0; i< size; i++) {
//         for(int j = i+1; j<size; j++) {
//             if(arr[i] == arr[j]) {
//                 cout << "Duplicate element : " << arr[i] << endl;
//                 break;
//             }
//         }
//     }
// }
// void findCommon(int arr1[], int arr2[], int n, int m) {
//     for(int i = 0; i < n; i++) {
//         int element = arr1[i];
//         for(int j = 0; j < m; j++) {
//             if(element == arr2[j]) {
//                 cout << element << " ";
//                 arr2[j] = INT_MIN;
//                 break;
//             }
//         }
//     }
// }
// void findInter(int arr1[], int arr2[], int n, int m) {
//     int i = 0, j = 0;
//     while(i<n && j<m) {
//         if(arr1[i] == arr2[j]) {
//             cout << arr1[i] << " ";
//             i++, j++;
//         }
//         else if(arr1[i] < arr2[j]) {
//             i++;
//         }
//         else if(arr1[i] > arr2[j]) {
//             j++;
//         }
//     }
// }
// void pairSum(int arr[], int m) {
//     int n;
//     cout << "Enter no. for sum of pairs from array : ";
//     cin >> n;
//     for(int i = 0; i<m; i++) {
//         for(int j = i+1; j<m; j++) {
//             if(arr[i] + arr[j] == n) {
//                 if(arr[i] > arr[j]) {
//                     break;
//                 }
//                 cout << arr[i] << " " << arr[j] << endl;
//             }
//         }
//     }
// }
// void tripletSum(int arr[], int m) {
//     int n;
//     cin >> n;
//     for(int i = 0; i<m; i++) {
//         for(int j=i+1; j<m; j++) {
//             for(int k = i+2; k<m; k++) {
//                 if(arr[i] + arr[j] + arr[k] == n) {
//                     cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
//                 }
//             }
//         }
//     }
// }
void printArray(int arr[], int n) {
    for(int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void sortOne(int arr[], int n) {
    int left = 0, right = n-1;
    while(left<right) {
        while(arr[left] == 0 && left<right) {
            left++;
        }
        while(arr[right] == 1&&left<right) {
            right--;
        }
        //if(arr[i] == 1 & arr[j] == 0)
        if(left<right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    // int size;
    // cin >> size;
    // int arr[100];
    // for(int i = 0; i<size; i++) {
    //     cin >> arr[i];
    // }
    // int unique = uniqueEle(arr, 100);
    // cout << "Unique element : " << uniqueEle(arr, size) << endl;
    // int arr[11] = {1, 2, 3, 4, 5, 8, 6, 7, 10, 9, 0};
    // int occurence = uniqueOcc(arr, 11);
    // int size;
    // cin >> size;
    // cout << "(Precaution) Enter any no. once or twice : ";
    // int arr[size];
    // for(int i = 0; i<size; i++) {
    //     cin >> arr[i];
    // }
    // int duplicate = findDuplicate(arr, size);
    // cout << "Duplicate input in array : " << duplicate << endl;
    // int doublet = findDoublet(arr, size);
//Intersection between two array which is nin unordered
    // int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    // int arr2[] = {3, 5, 10, 9, 11};
    // int n = sizeof(arr1)/sizeof(arr1[0]);
    // int m = sizeof(arr2)/sizeof(arr2[0]);
    // findCommon(arr1, arr2, n, m);
//Intersection between two array of non decreasing order
    // int arr1[] = {1, 3, 4, 5, 7, 9};
    // int arr2[] = {2, 3, 4, 5, 6};
    // int n = sizeof(arr1)/sizeof(arr1[0]);
    // int m = sizeof(arr2)/sizeof(arr2[0]);
    // findInter(arr1, arr2, n, m);
//Pair sum from an array
    // int arr[] = {0, 1, 2, -3, 4, 5, -6, 7, 8, 9};
    // int m = sizeof(arr)/sizeof(arr[0]);
    // pairSum(arr, m);
    // return 0;
//Triplet sum
    // int arr[] = {1, 3, 5, 2, 9, 6, 4, 8, 7};
    // int m = sizeof(arr)/sizeof(arr[0]);
    // tripletSum(arr, m);
    int arr[10] = {1, 0, 1, 0, 0, 1, 1, 0, 1, 0};
    sortOne(arr, 10);
    printArray(arr, 10);
}
