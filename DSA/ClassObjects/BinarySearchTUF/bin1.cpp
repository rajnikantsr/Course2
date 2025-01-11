#include<iostream>
using namespace std;
int searching(int arr[], int low, int high, int target) {
    int mid = low + (high-low)/2;
    if(low > high) return 0;
    if(arr[mid] == target) {
        return mid;
    } else if(arr[mid] > target) {
        return searching(arr, low, mid-1, target);
    } else {
        return searching(arr, mid+1, high, target);
    }
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target;
    cin >> target;
    cout << "Target found at index -> " << searching(arr, 0, n-1, target);
    return 0;
}