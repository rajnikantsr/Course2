#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int lowerBound(int arr[], int low, int high, int target) {
    int ans=high;
    while(low<=high) {
        int mid = low + (high-low)/2;
        if(arr[mid] >= target) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int upperBound(int arr[], int low, int high, int target) {
    int ans=high;
    while(low<=high) {
        int mid = low + (high-low)/2;
        if(arr[mid] > target) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    int arr[] = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target;
    cin >> target;
    int LB = lowerBound(arr, 0, n-1, target);
    cout << "Target found at index -> " << LB;
    cout << "After inserting value " << endl;
    int newArr[LB+1];
    for(int i = 0; i<LB; i++) {
        newArr[i] = arr[i];
    }
    newArr[LB] = target;
    for(int i = LB+1; i<n+1; i++) {
        newArr[i+1] = arr[i];
    } cout << endl;
    for(int i = 0; i<n+1; i++) {
        cout << newArr[i] << " ";
    } cout << endl;
    // cout << "Target found at index -> " << upperBound(arr, 0, n-1, target);
/*  //lowerbound using STL
    // vector<int> array = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
    // auto lb = lower_bound(array.begin(), array.end(), target);
    // if (lb != array.end()) {
    //     cout << "Lower bound of " << target << " is " << *lb << endl;
    // } else {
    //     cout << "Value not found" << endl;
    // }
*/
/*vector<int> array = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
    auto ub = upper_bound(array.begin(), array.end(), target);
    if (ub != array.end()) {
        cout << "upper bound of " << target << " is " << *ub << endl;
    } else {
        cout << "Value not found" << endl;
    }
*/ 
    return 0;
}