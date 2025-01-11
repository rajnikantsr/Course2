#include<iostream>
#include<vector>
using namespace std;
// // vector<int> wavePrint(vector<vector<int>>& arr, int nRows, int mCols) {
// //     vector<int> ans;
// //     for(int col = 0; col<mCols; col++) {
// //         if(col&1) {//odd index -> bottom to top
// //             for(int row = nRows-1; row>=0; row--) {
// //                 // cout << arr[row][col] << " ";
// //                 ans.push_back(arr[row][col]);
// //             }
// //         } else {//0 and Even index -> top to bottom
// //             for(int row = 0; row<nRows; row++) {
// //                 // cout << arr[row][col] << " "; 
// //                 ans.push_back(arr[row][col]);
// //             }
// //         }
// //     }
// //     return ans;
// // }
// vector<int> spiralPrint(vector<vector<int>>& arr) {
//     vector<int> ans;
//     int row = arr.size();
//     int col = arr[0].size();
//     int count = 0;
//     int total = row*col;
//     //Index of row/col
//     int startingRow = 0;
//     int endingRow = row-1;
//     int startingCol = 0;
//     int endingCol = col-1;
//     while(count<total) {
//         for(int index = startingCol; count<total && index<=endingCol; index++) {//Print starting row
//             ans.push_back(arr[startingRow][index]);
//             count++;
//         }
//         startingRow++;
//         for(int index = startingRow; count<total && index<=endingRow; index++) {//print ending col
//             ans.push_back(arr[index][endingCol]);
//             count++;
//         }
//         endingCol--;
//         for(int index = endingCol; count<total && index>=startingCol; index--) {//print ending row
//             ans.push_back(arr[endingRow][index]);
//             count++;
//         }
//         endingRow--;
//         for(int index = endingRow; count<total && index>=startingRow; index--) {//print starting col
//             ans.push_back(arr[index][startingCol]);
//             count++;
//         }
//         startingCol++;
//     }
//     return ans;
// }
vector<int> rotate90Degree(vector<vector<int>>& arr) {
    vector<int> ans;
    int row = arr.size();
    int col = arr[0].size();
    int count = 0;
    int total = row*col;
    //Index of row/col
    int startingRow = 0;
    int endingRow = row-1;
    int startingCol = 0;
    int endingCol = col-1;
    int i =0;
    while(i<col) {
        while(count < total) {
            for(int index = endingRow; index>=startingRow; index--) {
                ans.push_back(arr[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        i++;
    }
    return ans;
}
//Transpose
vector<vector<int>> transpose(vector<vector<int>>& arr, int row, int col) {

    vector<vector<int>> transposed(col, vector<int>(row));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            transposed[j][i] = arr[i][j];
        }
    }
    return transposed;
}
 
int main() {
    int nRows, mCols;
    cout << "Enter the number of rows: ";
    cin >> nRows;
    cout << "Enter the number of columns: ";
    cin >> mCols;

    vector<vector<int>> arr(nRows, vector<int>(mCols));

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < mCols; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Original matrix" << endl;
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < mCols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
/* 
    vector<int> result = wavePrint(arr, nRows, mCols);
    cout << "Wave print: ";
    for (int num : result) {
        cout << num << " ";
    }
*//*    
    vector<int> spiralResult = spiralPrint(arr);
    cout << "Spiral print : ";
    for(int num : spiralResult) {
        cout << num << " ";
    }
*/
/*//Method 1 Question Rotated matrix
    vector<int> result = rotate90Degree(arr);
    int row = arr.size(); // number of rows in the rotated matrix
    int col = arr[0].size(); // number of columns in the rotated matrix
    vector<vector<int>> rotatedMatrix(col, vector<int>(row));
    int index = 0;
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            rotatedMatrix[i][j] = result[index++];
        }
    }
    // print the rotated matrix
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cout << rotatedMatrix[i][j] << " ";
        }
        cout << endl;
    }
*/
/*Method 2
vector<vector<int>> rotated = transpose(arr, nRows, mCols);
Reverse each row of the transposed array
    for (int i = 0; i < mCols; i++) {
        int left = 0;
        int right = nRows - 1;
        while (left < right) {
            int temp = rotated[i][left];
            rotated[i][left] = rotated[i][right];
            rotated[i][right] = temp;
            left++;
            right--;
        }
    }

    cout << "Rotated array: " << endl;
    for (int i = 0; i < mCols; i++) {
        for (int j = 0; j < nRows; j++) {
            cout << rotated[i][j] << " ";
        }
        cout << endl;
    }
*/
    return 0;
}
