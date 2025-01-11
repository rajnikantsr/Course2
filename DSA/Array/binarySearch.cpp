#include<iostream>
// #include<algorithm>
using namespace std;

// int binarySearch(int arr[], int size, int key) {
//     int start = 0;
//     int end = size-1;
//     int mid = start + (end - start)/2;
//     while(start<=end) {
//         if(arr[mid] == key) {
//             return mid;
//         }
//         if(key > arr[mid]) {
//             start = mid + 1;
//         }
//         else {
//             end = mid - 1;
//         }
//         mid = start + (end - start)/2;
//     }
//     return -1;
// }
// int firstOcc(int brr[], int n, int key) {
//     int start = 0;
//     int end = n-1;
//     int ans = -1;
//     int mid = start + (end-start)/2;
//     while(start<=end) {
//         if(brr[mid] == key) {
//             ans = mid;
//             end = mid - 1;
//         }
//         else if(brr[mid] < key) {
//             start = mid + 1;
//         }
//         else {
//             end = mid - 1;
//         }
//         mid = start + (end-start)/2;
//     }
//     return ans;
// }
// int secOcc(int brr[], int n, int key) {
//     int start = 0;
//     int end = n-1;
//     int ans = -1;
//     int mid = start + (end-start)/2;
//     while(start<=end) {
//         if(brr[mid] == key) {
//             ans = mid;
//             start = mid + 1;
//         }
//         else if(brr[mid] < key) {
//             start = mid + 1;
//         }
//         else {
//             end = mid - 1;
//         }
//         mid = start + (end-start)/2;
//     }
//     return ans;
// }
// int peakElement(int arr[], int o) {
//     int start = 0;
//     int end = o-1;
//     int mid = start + (end-start)/2;
//     while(start<end) {
//         if(arr[mid] < arr[mid+1]) {
//             start = mid + 1;
//         }
//         else {
//             end = mid;
//         }
//         mid = start + (end-start)/2;
//     }
//     return start;
// }
// int pivotElement(int drr[], int p) {
//     int  s = 0;
//     int e = p - 1;
//     int mid = s + (e-s)/2;
//     while(s<e) {
//         if(drr[mid] >= drr[0]) {
//             s = mid+1;
//         }
//         else {
//             e = mid;
//         }
//         mid = s + (e-s)/2;
//     }
//     return s;
// }
// int findPosition(int drr[], int p, int s, int e, int key) {
//     int start = s;
//     int end = e;
//     int mid = start + (end - start)/2;
//     while(start<=end) {
//         if(drr[mid] == key) {
//             return mid;
//         }
//         if(key > drr[mid]) {
//             start = mid + 1;
//         }
//         else {
//             end = mid - 1;
//         }
//         mid = start + (end - start)/2;
//     }
//     return -1;   
// }
// long long int sqrtInteger(int n) {
//     int start = 0;
//     int end = n;
//     long long int mid  = start + (end-start)/2;
//     long long int ans = -1;
//     while(start<=end) {
//         long long int square = mid * mid;
//         if(square == n) {
//             return mid;
//         } 
//         if(square < n) {
//             ans = mid;
//             start = mid + 1;
//         }
//         else {
//             end = mid - 1;
//         }
//         mid = start + (end-start)/2;
//     }
//     return ans;
// }
// double morePrecision(int n, int precision, int tempSol) {
//     double factor = 1;
//     double ans = tempSol;
//     for(int i = 0; i<precision; i++) {
//         factor = factor/10;
//         for(double j = ans; j*j<n; j = j+factor) {
//             ans = j;
//         }
//     }
//     return ans;
// }
// bool isPossible(int frr[], int q, int n, int mid) {
//     int studentCount = 1;
//     int pageSum = 0;
//     for(int i = 0; i<q; i++) {
//         if(pageSum + frr[i] <= mid) {
//             pageSum += frr[i];
//         }
//         else {
//             studentCount++;
//             if(studentCount > n || frr[i] > mid) {
//                 return false;
//             }
//             pageSum = frr[i];
//         }
//     }
//    return true;
// }
// int bookAllocation(int frr[], int q, int n) {
//     int start = 0;
//     int sum = 0;
//     for(int i = 0; i<q; i++) {
//         sum += frr[i];
//     }
//     int end = sum;
//     int ans = -1;
//     int mid = start + (end-start)/2;
//     while(start <= end) {
//         if(isPossible(frr, q, n, mid)) {
//             ans = mid;
//             end = mid - 1;
//         }
//         else {
//             start = mid + 1;
//         }
//         mid = start + (end-start)/2;
//     }
//     return ans;
// }
// bool isPossible(int grr[], int r, int n, int mid) {
//     int painter = 1;
//     int pageSum = 0;
//     for(int i = 0; i<r; i++) {
//         if(pageSum + grr[i] <= mid) {
//             pageSum += grr[i];
//         }
//         else {
//             painter++;
//             if(painter > n || grr[i] > mid) {
//                 return false;
//             }
//             pageSum = grr[i];
//         }
//     }
//    return true;
// }
// int painterPart(int grr[], int r, int n) {
//     int s = 0;
//     int sum = 0;
//     for(int i = 0; i<r; i++) {
//         sum += grr[i];
//     }
//     int e = sum;
//     int ans = -1;
//     int mid = s + (e-s)/2;
//     while(s<=e) {
//     if(isPossible(grr, r, n, mid)) {
//         ans = mid;
//         e = mid - 1;
//     } else {
//         s = mid + 1;
//     }
//     mid = s + (e - s)/2;
//     }
//     return ans;
// }
bool isPossible(int stalls[], int s, int n, int mid) {
    int cowCount = 1;
    int lastPos = stalls[0];
    for(int i = 0; i<s; i++) {
        if(stalls[i] - lastPos >= mid) {
            cowCount++;
            if(cowCount == n) {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}
int agressiveCows(int stalls[], int s, int n) {
    // sort(stalls[0], stalls[s-1]);
    int mini = 0;
    int maxi = -1;
    for(int i = 0; i<s; i++) {
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi;
    int ans = -1;
    int mid = mini + (e-mini)/2;
    while(s<=e) {
        if(isPossible(stalls, s, n, mid)) {
            ans = mid;
            mini = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = mini + (e-mini)/2;
}
    return ans;
}
int main() {
    // int arr[] = {3, 7, 8, 9, 1, 2};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // int index = binarySearch(arr, size, 5);
    // cout << "Index of 5 : " << index << " ";
    // cout << endl;
    // int brr[] = {1, 2, 4, 4, 8, 8, 8, 8, 9, 9, 10};
    // int n = sizeof(brr)/sizeof(brr[0]);
    // int first = firstOcc(brr, n, 8);
    // cout << "Index of first occurence of key is : " << first << endl;
    // int second = secOcc(brr, n, 8);
    // cout << "Index of second occurence of key is : " << second << endl;
    // cout << "Total no. of occurence of key is : " << second-first + 1 << endl;
    // int crr[] = {4, 5 , 8, 9, 10, 11, 12, 3};
    // int o = sizeof(crr)/sizeof(crr[0]);
    // int peak = peakElement(crr, o);
    // cout << "Peak element : " << peak << endl;
    // int drr[] = {3, 8, 10, 17, 1};
    // int p = sizeof(drr)/sizeof(drr[0]);
    // int pivot = pivotElement(drr, p);
    // cout << "Pivoted element's index  : " << pivot << endl;
    // int key;
    // cin >> key;
    // if(key >= drr[pivot] && key <= drr[p-1]) {
    //     cout << findPosition(drr, p, pivot, p-1, key);
    // }
    // else {
    //     cout << findPosition(drr, p, 0, pivot-1, key);
    // }
    // int n;
    // cout << "Enter any no. for their square root in int value : ";
    // cin >> n;
    // int tempSol = sqrtInteger(n);
    // cout << "Answer is : " << morePrecision(n, 3, tempSol) << endl;
    // int frr[] = {30, 40, 10, 20};
    // int q = sizeof(frr)/sizeof(frr[0]);
    int n;
    cin >> n;
    // int allocation = bookAllocation(frr, q, n);
    // cout << "Maximum no. of pages assigned to a student : " << allocation << endl;
    // int grr[] = {2, 3, 4, 5, 6, 7};
    // int r = sizeof(grr)/sizeof(grr[0]);
    // int partition = painterPart(grr, r, n);
    // cout << "Minimum time required : " << partition << endl;
    int stalls[] = {2, 3, 4, 5, 6, 7};
    int s = sizeof(stalls)/sizeof(stalls[0]);
    int cows = agressiveCows(stalls, s, n);
    cout << "Min. distance : " << cows << endl;
    return 0;
}