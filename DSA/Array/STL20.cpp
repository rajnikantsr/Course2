#include<iostream>
#include<vector>
using namespace std;

// vector<int> reverse(vector<int> v) {
//     int s = 0, e = v.size()-1;
//     while(s<=e) {
//         swap(v[s], v[e]);
//         s++;
//         e--;
//     }
//     return v;
// }
// vector<int> revindex(vector<int> v, int n) {
//     int s = n+1, e = v.size()-1;
//     while(s<=e) {
//         swap(v[s], v[e]);
//         s++;
//         e--;
//     }
//     return v;
// }
// void print(vector<int> v) {
//     for(int i = 0; i<v.size(); i++) {
//         cout << v[i] << " ";
//     } cout << endl;
// }
// void merge2(vector<int>& num1, const vector<int>& num2) {
//     int i = 0, j = 0;
//     while(i<num1.size() && j<num2.size()) {
//         if(num1[i] <= num2[j]){
//             i++;
//         } else {
//             num1.insert(num1.begin()+i, num2[j]);
//             j++;
//         }
//     }
//     num1.insert(num1.end(), num2.begin()+j, num2.end()); 
// }
// void merge(vector<int>& arr2, const vector<int>& arr3, vector<int>& arr4) {
//     int i = 0, j = 0;
//     while(i<arr2.size() && j<arr3.size()) {
//         if(arr2[i] <= arr3[j]) {
//             arr4.push_back(arr2[i]);
//             i++;
//         } else {
//             arr4.push_back(arr3[j]);
//             j++;
//         }
//     }
//     while(i<arr2.size()) {
//         arr4.push_back(arr2[i]);
//         i++;
//     }
//     while(j<arr3.size()) {
//         arr4.push_back(arr3[j]);
//         j++;
//     }
// }
void moveZero(vector<int> zero) {
    int nonZero = 0;
    for(int j = 0; j<zero.size(); j++) {
        if(zero[j] != 0) {
            swap(zero[j], zero[nonZero]);
            i++;
        } 
    }
    for(auto elem : zero) {
        cout << elem << " ";
    }
}

int main() {
    // vector<int> v;
    // v.push_back(11);
    // v.push_back(7);
    // v.push_back(3);
    // v.push_back(12);
    // v.push_back(14);
    // vector<int> ans = reverse(v);
    // print(ans);
    // int n;
    // cin >> n;
    // vector<int> ans2 = revindex(v, n);
    // print(ans2);
    // vector<int> num1 = {1, 2, 3};
    // vector<int> num2 = {2, 5, 6};
    // merge2(num1, num2);
    // for(auto elem : num1) {
    //     cout << elem << " ";
    // }
    // vector<int> arr2 = {1, 3, 5 , 7, 9};
    // vector<int> arr3 = {2, 4, 6};
    // vector<int> arr4 = {};
    // merge(arr2, arr3, arr4);
    // for(auto elem : arr4) {
    //     cout << elem << " ";
    // }
    vector<int> zero = {0, 1, 0, 3, 12};
    moveZero(zero);
    return 0;
}

