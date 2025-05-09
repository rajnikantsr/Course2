#include <iostream>
#include <vector>
using namespace std;

int searching(vector<int> arr, int low, int high, int target) {
    if (low > high) return -1;
    
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target) {
        // Check if it's the first occurrence
        if (mid == 0 || arr[mid - 1] < target)
            return mid;
        else
            return searching(arr, low, mid - 1, target);
    }
    else if (arr[mid] < target) {
        return searching(arr, mid + 1, high, target);
    }
    else {
        return searching(arr, low, mid - 1, target);
    }
}
int lowerBound(vector<int> arr, int low, int high, int target) {
    int mid = low + high / 2;
    int ans = arr.size();
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= target) {
            ans = mid;           // potential answer
            high = mid - 1;      // look on the left
        } else {
            low = mid + 1;       // look on the right
        }
    }
    return ans;
}
vector<int> insert(vector<int> arr, int N, int target) {
        vector<int> temp;
        int position = searchPosition(arr, N, target);  // find the correct insert position
        for (int i = 0; i < position; i++) {
            temp.push_back(arr[i]);  // add elements before the insert position
        }
        temp.push_back(target);  // insert the target
        for (int i = position; i < N; i++) {
            temp.push_back(arr[i]);  // add the remaining elements after the target
        }
        return temp;
    }

int searchPosition(vector<int> arr, int N, int target) {
        int low = 0, high = N - 1;
        int ans = N;  // default to N (past the end)

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[mid] > target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;  // position to insert the target
    }
vector<int> searchInsertK(vector<int>Arr, int k) {
    int N = Arr.size();
        return insert(Arr, N, k); 
}
int main() {
    vector<int> arr = {1, 2, 3, 6, 7};
    int low = 0, high = arr.size() - 1, target = 4;
    // cout << searching(arr, low, high, target);
    // cout << lowerBound(arr, low, high, target);
    vector<int> temp = searchInsertK(arr, target);
    for(auto i : temp) {
        cout << i << " ";
    }
    return 0;
}
