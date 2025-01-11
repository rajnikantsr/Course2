#include <iostream>
#include<string>
using namespace std;
bool isSorted(int *arr1, int n, int i = 1) {
    if(i == n || n == 0) return true;
    if(arr1[i] < arr1[i-1]) return false;
    return isSorted(arr1+1, n-1, i+1);
}
// int sumOfArray(int arr1[], int n, int sum = 0, int i = 0) {
//     if(i == n) return sum;
//     sum = sum + arr1[i];
//     return sumOfArray(arr1, n, sum, i+1);
// }
int sumOfArray(int arr1[], int size) {
    if(size == 0) {
        return 0;
        }
    if(size == 1) {
        return arr1[0];
        }
    int sum = arr1[0] + sumOfArray(arr1+1, size-1);
    return sum;
}
bool linearSearch(int arr1[], int n, int target) {
    if(n == 0) return false;
    if(arr1[0] == target) return true;
    return linearSearch(arr1+1, n-1, target);
}
int print(int *arr2, int s, int e) {
    for(int i = s; i<=e; i++) {
        cout << arr2[i] << " ";
    } cout << endl;
}
bool binarySearch(int arr2[], int n, int s, int e, int target) {
    print(arr2, s, e);
    cout << endl;
    if(s>e) return false;
    int mid = s + (e-s)/2; 
    if(arr2[mid] == target) return true;
    if(arr2[mid] < target) {
        return binarySearch(arr2, n, mid+1, e, target);
    } else {
        
        return binarySearch(arr2, n, s, mid-1, target);
    }
}
int firstOcc(int arr1[], int size, int s, int e, int target) {
    int ans = -1;
    int mid = s + (e-s)/2;
    if(s>=e) return ans;
    if(arr1[mid] == target) return mid;
    if(arr1[mid] > target) {
        e = mid - 1;
        firstOcc(arr1, size, s, e, target);
    } else {
        s = mid + 1;
        firstOcc(arr1, size, s, e, target);
    }
}
void reverseArray(string& str, int i, int o) {
    if (i >= o/2) return;
    char temp = str[i];
    str[i] = str[o-1-i];
    str[o-1-i] = temp;
    reverseArray(str, i + 1, o);
}
bool checkPalindrome(string str, int i, int size) {
    if(i >= size/2) return true;
    if(str[i] == str[size-i-1]) {
        return checkPalindrome(str, i+1, size);
    } else {
        return false;
    }
}
int power(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    //Recursive call
    int ans = power(a, b/2);
    //If b is odd
    if(b%2 == 0) {
        return ans * ans;
    } else {
        return a * ans * ans;
    }
}
void bubbleSortRecursion(int *arr3, int size) {
    if(size == 0 || size == 1) return ;
    for(int i = 1; i < size; i++) {
        if(arr3[i-1] > arr3[i]) {
            swap(arr3[i-1], arr3[i]);
        }
    }
    bubbleSortRecursion(arr3, size-1);
}
void selectionSort(int *arr3, int size) {
    if(size == 1 || size == 0) return;
    
    int minIndex = 0;
    for(int i = 1; i < size; i++) {
        if(arr3[i] < arr3[minIndex]) {
            minIndex = i;
        }
    }
    swap(arr3[0], arr3[minIndex]);
    selectionSort(arr3 + 1, size - 1);
}
void insertionSort(int *arr3, int size) {
    if(size == 1 || size == 0) return;
    
    insertionSort(arr3, size-1);
    
    int temp = arr3[size-1];
    int j = size-2;
    
    while(j >= 0 && arr3[j] > temp) {
        arr3[j+1] = arr3[j];
        j--;
    }
    
    arr3[j+1] = temp;
    insertionSort(arr3, size);
}
int main() {
    // int arr1[] = {2, 4, 5, 6, 7, 10, 10};
    // int n = sizeof(arr1)/sizeof(arr1[0]);
    // int sum, i = 0;
    // cout << isSorted(arr1, n) << endl;
    // cout << sumOfArray(arr1, n) << endl;
    // int target;
    // cin >> target;
    // cout << linearSearch(arr1, n, target) << endl;
    // int arr2[] = {1, 3, 5, 7, 9, 11, 14};
    // int m = sizeof(arr2)/sizeof(arr2[0]);
    // int s = 0;
    // int e = m-1;
    // cout << binarySearch(arr2, m, s, e, target) << endl;
    // cout << firstOcc(arr1, n, s, e, target);
    // string str = "KANAK";
    // int o = str.length();
    // reverseArray(str, 0, o);
    // cout << str << endl;
    // cout << checkPalindrome(str, 0, o);
    // int a, b;
    // cin >> a >> b;
    // cout << power(a, b) << endl;
    int arr3[] = {1, 4, 3, 8, 50, 2};
    int p = sizeof(arr3)/sizeof(arr3[0]);
    bubbleSortRecursion(arr3, p);
    for(int i = 0; i<p; i++) {
        cout << arr3[i] << " ";
    } cout << endl;
    selectionSort(arr3, p);
    for(int i = 0; i<p; i++) {
        cout << arr3[i] << " ";
    } cout << endl;
    insertionSort(arr3, p);
    for(int i = 0; i<p; i++) {
        cout << arr3[i] << " ";
    } cout << endl;
    return 0;
}