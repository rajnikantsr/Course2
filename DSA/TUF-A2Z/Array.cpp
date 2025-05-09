#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isSortedRotated(vector<int>&nums, int n) {
        vector<int> ans(nums.begin(), nums.end());
        sort(ans.begin(), ans.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums == ans) {
                return true;
            }
            rotate(nums.begin(), nums.begin() + 1, nums.end());
        }
        return false;
}
int removeDuplicate(vector<int> &dup, int n) {
    int i = 0;
    for(int j = 1; j<n; j++) {
        if(dup[j] != dup[i]) {
            dup[i+1] = dup[j];
            i++;
        }
    }
    return i+1;
}
int main() {
/*    //Largest and second largest->Time complexity = O(nlogn)
    int arr[5] = {1, 3, 4, 4, 2};
    int largest = arr[0];
    int secLargest = -1;
    for(int i = 0; i<5; i++) {
        if(arr[i] > largest) {
            secLargest = largest;
            largest = arr[i];           
        }
        else if(arr[i] < largest && arr[i] > secLargest) {
            secLargest = arr[i];
        }
    }
    cout << "Largest element in an array : " << largest << endl;
    cout << "Second Largest element in an array : " << secLargest << endl;*/
    //Check array is sorted and rotated
/*  Check array is sorted rotated
    vector<int> nums = {1, 4, 6, 2, 5};
    int n = sizeof(nums);
    if(isSortedRotated(nums, n)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
        }*/
/*    //Remove all duplicates element in place of it
    vector<int> dup = {1, 2, 2, 3, 3, 4, 4, 4};
    int n = dup.size();
    int newSize = removeDuplicate(dup, n);
    for(int i = 0; i<newSize; i++) {
        cout << dup[i] << " " ;
    }*/
    return 0;
}