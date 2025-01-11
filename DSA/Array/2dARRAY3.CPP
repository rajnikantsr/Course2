#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool binarySearch(vector<vector<int>>& arr, int target) {
    int row = arr.size();
    int col = arr[0].size();
    int start = 0;
    int end = row*col-1;
    int mid = start+(end-start)/2;
    while(start<=end) {
        int element = arr[mid/col][mid%col];
        if(element == target) {
            return 1;
        }
        if(element < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return 0;
}
bool binarySearch2(vector<vector<int>>& arr, int target) {
    int row = arr.size();
    int col = arr[0].size();
    int rowIndex = 0;
    int colIndex = col - 1;
    while(rowIndex < row && colIndex >= 0) {
        int element = arr[rowIndex][colIndex];
        if(element == target) {
            return 1;
        }
        if(element > target) {
            colIndex--;
        } else {
            rowIndex++;
        }
    }
    return 0;
}
vector<int> factorial(int n) {
    vector<int> ans(1, 1);
    while(n>1) {
        int carry = 0, res;
        int size = ans.size();
        for(int i = 0; i<size; i++) {
            res = (ans[i]*n) + carry;
            ans[i] = res%10;
            carry = res/10;
        }
        while(carry) {
            ans.push_back(carry%10);
            carry /= 10;
        }
        n--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int num(char c) {
    if(c == 'I') {
        return 1;
    }
    else if(c == 'V') {
        return 5;
    }
    else if(c == 'X') {
        return 10;
    }
    else if(c == 'L') {
        return 50;
    } 
     else if(c == 'C') {
        return 100;
     }
    else if(c == 'D') {
        return 500;
    } else {
        return 1000;
    }
}
int romTOint(string input) {
    int sum = 0;
    for (int i = 0; i < input.length(); i++) {
        if (i + 1 < input.size() && num(input[i]) < num(input[i + 1])) {
            sum -= num(input[i]);
        } else {
            sum += num(input[i]);
        }
    }
    return sum;
}
int main() {
    // vector<vector<int>> arr = {{1, 3, 4, 6}, {7, 8, 9, 10}, {13, 15, 16, 19}};
    // vector<vector<int>> arr = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 16}, {3, 6, 9, 17, 19}, {4, 13, 14, 18, 23}, {5, 20, 21, 22, 24}}; 
    // int target;
    // cout << "Enter Target : ";
    // cin >> target;
    // cout << endl;
    // if(binarySearch(arr, target)) {
    //     cout << "Target found: " << target << endl;
    // } else {
    //     cout << "Target not found" << endl;
    // }
    // if(binarySearch2(arr, target)) {
    //     cout << "Target found : " << target;
    // } else {
    //     cout << "Target Not found"; 
    // }
    // int n;
    // cin >> n;
    // vector<int> fact = factorial(n);
    // for(int num : fact) {
    //     cout << num << " ";
    // }
    string input;
    cin >> input; // Initialize the vector with size n
    cout << "Your total sum of each char of roman no. : " << romTOint(input);
    return 0;
}