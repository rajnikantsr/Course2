#include <iostream>
using namespace std;

int maxOfArray(int *arr, int size) {
    int temp = arr[0];
    for(int i = 1; i < size; i++) {
        if(temp < arr[i]) {
            temp = arr[i];
        }
    }
    return temp;
}
int minOfArray(int *arr, int size) {
    int temp = arr[0];
    for(int i = 1; i < size; i++) {
        if(temp > arr[i]) {
            temp = arr[i];
        }
    }
    return temp;
}
bool possible(int *arr, int size, int day, int m, int k) {
    int cnt = 0, noOfBouquets = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] <= day) { 
            cnt++;
        } else {
            noOfBouquets += cnt / k;
            cnt = 0;
        }
    }
    noOfBouquets += cnt / k;
    return noOfBouquets >= m; // Always return a boolean
}
int minDaysToMakeBouquets(int *arr, int size, int m, int k) {
    if (size < m * k) return -1; // Ensure enough flowers are available
    int low = minOfArray(arr, size);
    int high = maxOfArray(arr, size);
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (possible(arr, size, mid, m, k)) {
            high = mid - 1; // Reduce search space
        } else {
            low = mid + 1;
        }
    }
    return low;
}
int ceil(int num, int j) {
    return (num + j - 1) / j;  // Proper ceiling function
}
// int getSmallerDivisor(int *arr, int size, int threshold) {
//     if(threshold < size) return -1;  // Ensures valid input
//     int maxValue = maxOfArray(arr, size);
//     for(int i = 1; i <= maxValue; i++) {
//         int sum = 0;
//         for(int j = 0; j < size; j++) { // Loop through the array elements
//             sum += ceil(arr[j], i);  // Correct function call
//         }
//         if(sum <= threshold) {  // Proper condition
//             return i;
//         }
//     }
//     return -1; // Return -1 if no divisor is found
// }
int sumOfSmaller(int* arr, int size, int divisor) {
    int sum = 0;
    for(int i = 0; i<size; i++) {
        sum += ceil(arr[i], divisor);
    }
    return sum;
}
int getSmallerDivisor(int* arr, int size, int threshold) {
    int low = 1, high = maxOfArray(arr, size);
    int ans = -1;
    while(low<=high) {
        int mid = low + (high-low)/2;
        if(sumOfSmaller(arr, size, mid) <= threshold) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int getDays(int n, int *weight, int cap) {
    int days = 1, load = 0;

    for(int i = 0; i < n; i++) {
        if(load + weight[i] > cap) {
            days++; 
            load = weight[i]; 
        } else {
            load += weight[i];  
        }
    }
    return days;  
}
int leastCapacity(int *weight, int n, int days) {
    int low = maxOfArray(weight, n);  
    int high = 0;
    
    for(int i = 0; i < n; i++) {
        high += weight[i];  
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int noOfDays = getDays(n, weight, mid);
        
        if (noOfDays <= days) {
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }
    
    return low;  
}
int getKthMissingNo(int *arr, int n, int k) {
    for(int i = 0; i<n; i++) {
        if(arr[i] < k) {
            k++;
        } else {
            break;
        }
    }
    return k;
}
int kthMissingTerm(int *arr, int n, int k) {
    int low = 0, high = n-1;
    while(low<=high) {
        int mid = low + (high - low)/2;
        int missing = arr[mid] - (mid + 1);
        if(missing<k) low = mid + 1;
        else high = mid-1;
    }
    return high + 1 + k;
}
int main() {
    int arr[] = {7, 7, 7, 7, 13, 11, 12, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m, k;
    
    // cout << "Enter no of bouquets required -> ";
    // cin >> m;
    // cout << "Enter no of adjacent flowers required -> ";
    // cin >> k;
    // int result = minDaysToMakeBouquets(arr, n, m, k);
    // if (result == -1) {
    //     cout << "It is not possible to make the required bouquets." << endl;
    // } else {
    //     cout << "Minimum days required: " << result << endl;
    // }  
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int l = sizeof(arr2)/sizeof(arr2[0]);
    // int threshold;
    // cin >> threshold;
    // cout << getSmallerDivisor(arr2, l, threshold);
    // int days = 5;
    // cout << leastCapacity(arr2, l, days);
    int arr3[] = {2, 3, 4, 7, 11};
    int p = 5;
    int o = sizeof(arr3)/sizeof(arr3[0]);
    //Approach 1
    cout << getKthMissingNo(arr3, o, p);//O size of array, p = kth missing term
    cout << endl;
    //Approach 2
    cout << kthMissingTerm(arr3, o, p);
    return 0;
}   