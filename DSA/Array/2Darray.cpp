#include<iostream>
#include<climits>
using namespace std;
bool isPresent(int arr[][4], int target, int row, int col) {
    for(int row = 0; row<3; row++) {
        for(col = 0; col<4; col++) {
            if(arr[row][col] == target) {
                return 1;
            } 
        }
    }
    return 0;
}
void printingSum(int arr[][4], int row, int col) {
    cout << "Printing sum : ";
    for(int row = 0; row<3; row++) {
        int sum = 0;
        for(int col = 0; col<4; col++) {
            sum += arr[row][col];
        }
        cout << sum << endl;
    }
    cout << endl;
}
void printingsum(int arr[][4], int row, int col) {
    cout << "Printimg sum : ";
    for(int col = 0; col<4; col++) {
        int sum = 0;
        for(int row = 0; row<3; row++) {
            sum+=arr[row][col];
        }
        cout << sum << " ";
    }
    cout << endl;
}
void getMaxSum(int arr[][4], int row, int col) {
    int max = INT_MIN;
    int rowIndex = -1;
    for(int row = 0; row<3; row++) {
        int sum = 0;
        for(int col = 0; col<4; col++) {
            sum+=arr[row][col];
            if(sum>max) {
                max = sum;
                rowIndex = row;
            }
        }
    }
    cout << "Maximum value of sum wrt. rows : " << rowIndex << "th row : " <<max << endl;
}
int main() {
    int arr[3][4];
    // int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};//Initialised as row wise
    // int arr[3][4] = {{1, 2, 3, 4}, {11, 22, 33, 44}, {111, 222, 333, 444}};
    cout << "Enter input's : ";
    // for(int row = 0; row<3; row++) {// taking input ->Row wise
    //     for(int col = 0; col<4; col++) {
    //         cin >> arr[row][col];
    //     }
    // }
    for(int col = 0; col<4; col++) {//taking input -> Col wise
        for(int row = 0; row<3; row++) {
            cin >> arr[row][col];
        }
    }
    for(int row = 0; row<3; row++) {
        for(int col = 0; col<4; col++) {
            cout << arr[row][col] << "    ";
        }
        cout << endl;
    }

    // cout << "Enter the element to search for : ";
    // int target;
    // cin >> target;
    // if(isPresent(arr, target, 3, 4)) {
    //     cout << "Found" << endl;
    // } else {
    //     cout << "Not found " << endl; 
    // }
    // printingSum(arr, 3, 4);
    // printingsum(arr, 3, 4);
    getMaxSum(arr, 3, 4);
    return 0;
}