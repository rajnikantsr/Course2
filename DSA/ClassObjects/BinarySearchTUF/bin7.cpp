#include <iostream>
#include <vector>
#include<climits>
#include <algorithm> // For sort()

using namespace std;
int max(vector<int> arr, int n) {
    int maxi = INT_MIN;
    for(int i = 0; i<n; i++) {
        if(arr[i] > maxi) {
            maxi = arr[i];
        }
    }
    return maxi;
}
int sum(vector<int> arr, int n) {
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum+=arr[i];
    }
    return sum;
}
bool canWePlace(vector<int> arr, int minDis, int cows, int n) {
    int cntCows = 1, last = arr[0];
    for(int i = 0; i<n; i++) {
        if(arr[i]-last >= minDis) {
            cntCows++;
            last = arr[i];
        }
    }
    if(cntCows >= cows) {
        return true;
    } else {
        return false;
    }
}
int minDistOfAG(vector<int>& arr, int cows) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int low = 0, high = arr[n-1]-arr[0], ans = -1;
    while(low<=high) {
        int mid = low + (high-low)/2;
        if(canWePlace(arr, mid, cows, n)) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return high;//Or return ans;
}
int noOfStudents(const vector<int>& arr, int possiblePages, int n) {
    int students = 1, pagesStudent = 0;

    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= possiblePages) {
            pagesStudent += arr[i];
        } else {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int bookAllocation(vector<int>& arr, int students, int n) {
    if (students > n) return -1;
    int low = max(arr, n);
    int high = sum(arr, n);
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (noOfStudents(arr, mid, n) > students) {
            low = mid + 1; 
        } else {
            ans = mid;
            high = mid - 1; 
        }
    }
    return ans;
}
int main() {
    vector<int> arr = {0, 3, 4, 7, 9, 10};
    int n = arr.size();
    // int cows;
    // cout << "Enter no. of cows: ";
    // cin >> cows;
    // int aggresiveCows = minDistOfAG(arr, cows);
    // cout << "Largest minimum distance: " << aggresiveCows << endl;
    int students;
    cout << "Enter no. of students" << endl;
    cin >> students;
    cout <<  bookAllocation(arr, students, n);
    return 0;
}
