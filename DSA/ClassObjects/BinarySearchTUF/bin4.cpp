#include<iostream>
#include<climits>
using namespace std;
int isPresent(int *arr, int n, int target) {
    int low = 0;
    int high = n-1;
    while(low<=high) {
        int mid = low + (high-low)/2;
        if(arr[mid] == target) return mid;
        if(arr[low] <= arr[mid]) {
            if(arr[low] <= target && target <= arr[mid]) {
                high = mid-1;
            } else {
                low = mid + 1;
            }
        } else {
            if(arr[mid] <= target && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int IsPresent(int *arr, int n, int target) {
    int low = 0;
    int high = n-1;
    while(low<=high) {
        int mid = low + (high-low)/2;
        if(arr[mid] == target) return mid;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }
        if(arr[low] <= arr[mid]) {
            if(arr[low] <= target && target <= arr[mid]) {
                high = mid-1;
            } else {
                low = mid + 1;
            }
        } else {
            if(arr[mid] <= target && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int minimum(int e1, int e2) {
    if(e1>e2) {
        return e2;
    } else {
        return e1;
    }
}
int getMinimum(int* arr, int n) {
    int l = 0;
    int h = n-1;
    int ans = INT_MAX;
    int index = -1;
    while(l<=h) {
        int m = (l + h)/2;
        if(arr[l]<=arr[h]) {
            if(arr[l] < ans) {
                index = l;
                ans = arr[l];
            }
            break;
        }
        if(arr[l] <= arr[m]) {
            if(arr[l] < ans) {
                index = l;
                ans = arr[l];
            }
            l = m+1;
        } else {
            h = m-1;
            if(arr[m]<ans) {
                index = m;
                ans = arr[m];
            }
        }
    }
    cout << "Index of minimum element->" << index << endl;
    return ans;
}
int main() {
    int arr[] = {7, 8, -1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Index of target element->" << isPresent(arr, n, 79) << endl;//Unique target element is present in an array
    int arr1[] = {3, 1, 2, 3, 3, 3, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    cout << "Index of target element-> " << IsPresent(arr1, m, 3) << endl;//Duplicate target element is present in an array
    cout << "Minimum element is -> " << getMinimum(arr, n);
    return 0;
}