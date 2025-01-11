#include<iostream>
#include<vector>
using namespace std;

// void rotateArray(vector<int> nums, int k) {
//     vector<int> temp(nums.size());
//     for(int i = 0; i<nums.size(); i++) {
//         temp[(i+k)%nums.size()] = nums[i];
//     } 
//     nums = temp;
// }
bool isSortedRotated(vector<int>& nums, int n) {
    if (n <= 1) {
        return true;  // empty or single-element array is sorted and rotated
    }

    int count = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i-1] > nums[i]) {
            count++;
        }
    }
    if (nums[n-1] > nums[0]) {
        count++;
    }

    return count <= 1;
}
// void twoArraySum(vector<int> &arr1, vector<int> &arr2) {
//     int i = arr1.size() - 1;
//     int j = arr2.size() - 1;
//     vector<int> ans;
//     int carry = 0;
//     while(i >= 0 && j >= 0) {
//         int val1 = arr1[i];
//         int val2 = arr2[j];
//         int sum = val1 + val2 + carry;
//         carry = sum/10;
//         sum = sum%10;
//         ans.push_back(sum);
//         i--;
//         j--;
//     }
//     //First case
//     while(i >= 0) {
//         int sum = arr1[i] + carry;
//         carry = sum/10;
//         sum = sum%10;
//         ans.push_back(sum);
//         i--;
//     }
//     //Second case
//     while(j >= 0) {
//         int sum = arr2[j] + carry;
//         carry = sum/10;
//         sum = sum%10;
//         ans.push_back(sum);
//         j--;
//     }
//     while(carry != 0) {
//         int sum = carry;
//         carry = carry/10;
//         sum = sum%10;
//         ans.push_back(sum);

//     }
//     for (int c = ans.size() - 1; c >= 0; c--) {
//         cout << ans[c] << " ";
//     }
//     cout << endl;

// }
int main() {
    // vector<int> nums = {11, 12, 13, 14, 15};
    // int k;
    // cin >> k;
    // rotateArray(nums, k);
    // for(auto i : nums) {
    //     cout << i << " ";
    // }
    vector<int> nums = {1, 1, 1};
    int n = nums.size();
    cout << "Array is both sorted and rotated or not : " << isSortedRotated(nums, n) << endl;
    // vector<int> arr1 = {9, 9, 9};
    // vector<int> arr2 = {9, 9, 9};
    // twoArraySum(arr1, arr2);
    return 0;
}
