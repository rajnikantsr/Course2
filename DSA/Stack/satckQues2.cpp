#include<iostream>
#include<stack>
#include<vector>
#include<climits>
using namespace std;

int isCelebrity(int M[3][3], int n) {
    int ans = -1;
    
    for(int i = 0; i < n; i++) {
        bool rowCheck = true;
        for(int j = 0; j < n; j++) {
            if(i != j && M[i][j] != 0) {  // Celebrity shouldn't know anyone
                rowCheck = false;
                break;
            }
        }

        if(rowCheck) {
            bool colCheck = true;
            for(int j = 0; j < n; j++) {
                if(i != j && M[j][i] != 1) {  // Everyone should know the celebrity
                    colCheck = false;
                    break;
                }
            }

            if(colCheck) return i; // Found the celebrity
        }
    }
    
    return -1; // No celebrity found
}
bool knows(int M[3][3], int a, int b, int n) {
    if(M[a][b] == 1) {
        return true;
    } else {
        return false;
    }
}
int IsCelebrity(int M[3][3], int n) {
    stack<int> s;
    for(int i = 0; i<n; i++) {
        s.push(i);
    }
    while(s.size() > 1) {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        if(knows(M, a,b, n)) {
            s.push(b);
        } else {
            s.push(a);
        }
    }
    bool rowCheck = false;
    int candidate = s.top();
    int zeroCount = 0;
    //Row check
    for(int i = 0; i<n; i++) {;
        if(M[candidate][i] == 0) {
            zeroCount++;
        }
    }
    if(zeroCount == n) {
        rowCheck = true;
    }
    //Column check
    bool colCheck = false;
    int oneCount = 0;
    for(int i = 0; i<n; i++) {
        if(M[i][candidate] == 1) {
            oneCount++;
        }
    }
    if(oneCount == n-1) {
        colCheck = true;
    }
    if(rowCheck == true && colCheck == true) {
        return candidate;
    } else {
        return -1;
    }
}
vector<int> nextSmallerElement(int* arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = n-1; i>=0; i--) {
        while(s.top() != -1 && arr[i] <= arr[s.top()]) {  // Fix condition
            s.pop();
        }
        ans[i] = s.top() == -1 ? n : s.top();  // Assign index instead of value
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement(int* arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = 0; i<n; i++) {
        while(s.top() != -1 && arr[i] <= arr[s.top()]) {  // Fix condition
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangularArea(int* arr, int n) {
    vector<int> next = nextSmallerElement(arr, n);
    vector<int> prev = prevSmallerElement(arr, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++) {
        int l = arr[i];
        if (next[i] == -1) { // Fix boundary condition
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;
        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}
int maxAreaOfRectangle(int M[4][4], int n, int m) {
    int area = largestRectangularArea(M[0], m);
    for(int i = 1; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(M[i][j] != 0) {
                M[i][j] = M[i][j] + M[i-1][j];
            } else {
                M[i][j] = 0;
            }
        }
        area = max(area, largestRectangularArea(M[i], m));
    }
    return area;
}
int main() {
    int M[3][3] = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    int M1[4][4] = {{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};

    cout << IsCelebrity(M, 3) << endl;
    cout << maxAreaOfRectangle(M1, 4, 4);
    return 0;
}
