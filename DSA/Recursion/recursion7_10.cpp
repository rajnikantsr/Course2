#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to generate all subsets
void solve(vector<int>& nums, vector<int>& output, int index, vector<vector<int>>& ans) {
    if (index >= nums.size()) {
        ans.push_back(output);
        return;
    }
    // exclude
    solve(nums, output, index + 1, ans);
    // include
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
    output.pop_back(); // backtrack
}

vector<vector<int>> subset(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}

// Function to generate all subsequences
void solve1(string str, string& output, int index, vector<string>& ans) {
    if(index >= str.size()) {
        ans.push_back(output);
        return;
    }
    // exclude
    solve1(str, output, index+1, ans);
    // include
    output += str[index];
    solve1(str, output, index+1, ans);
    output.pop_back(); // backtrack
}
vector<string> subsequences(string& str) {
    vector<string> ans;
    string output = "";
    solve1(str, output, 0, ans);
    return ans;
}
void solve2(string digits, string output, int index, vector<string>& ans, string mapping[]) {
    if(index >= digits.length()) {
        ans.push_back(output);
        return ;
    }
    int number = digits[index] - '0';
    string value = mapping[number];
    for(int i = 0; i<value.length(); i++) {
        output.push_back(value[i]);
        solve2(digits, output, index+1, ans, mapping);
        output.pop_back();
    }
}
vector<string> keypadProblem(string digits) {
    vector<string> ans;
    if(digits.length() == 0) return ans;
    string output = "";
    int index = 0;
    string mapping[10] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve2(digits, output, index, ans, mapping);
    return ans;
}
void solve3(vector<int>& permute, int index, vector<vector<int>>& ans) {
    if (index >= permute.size()) {
        ans.push_back(permute);
        return;
    }
    for (int j = index; j < permute.size(); j++) {
        swap(permute[index], permute[j]);
        solve3(permute, index + 1, ans);
        // Backtracking
        swap(permute[index], permute[j]);
    }
}

vector<vector<int>> permutation(vector<int>& permute) {
    vector<vector<int>> ans;
    int index = 0;
    solve3(permute, index, ans);
    return ans;
}
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subset(nums);
    cout << "Subsets of the array are:" << endl;
    for (const auto& subset : ans) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    string str = "abc";
    vector<string> ans1 = subsequences(str);
    cout << "\nSubsequences of the string are:" << endl;
    for (const auto& seq : ans1) {
        cout << seq << endl;
    } cout << endl;
    string digits = "23";
    vector<string> ans2 = keypadProblem(digits);
    cout << "Possible outcomes of given number : " << endl;
    for(const auto& seq : ans2) {
        cout << seq << endl;
    } cout << endl;
    vector<int> permute = {1, 2, 3};
    vector<vector<int>> ans3 = permutation(permute);
    cout << "Possible outcomes of given number : " << endl;
    for (const auto& seq : ans3) {
        for (int num : seq) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}