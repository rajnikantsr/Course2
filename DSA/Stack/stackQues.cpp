#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<climits>
using namespace std;
void deleteMiddle(stack<int> &s, int cnt, int size) {
    if(cnt == size/2) {
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();
    deleteMiddle(s, cnt+1, size);
    s.push(num);
}
char matches(char top, char ch) {}
bool isValidParenthesis(string str) {
    stack<char> s;
    for(int i = 0; i<str.size(); i++) {
        char ch = str[i];
        if(ch == '{' || ch == '(' || ch == '[') {
            s.push(ch);
        } else {
            if(!s.empty()) {
                char top = s.top();
                if((ch == '}' && top == '{') || (ch == ')' && top == '(') || (ch == ']' && top == '[')) {
                    s.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    if(s.empty()) {
        return true;
    } else {
        return false;
    }
}
void insertAtBottom(stack<int> &s, int element) {
    if(s.empty()) {
        s.push(element);
        return;
    }
    int num = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(num);
}
void reverseStack(stack<int> &s) {
    if(s.empty() ) {
        return;
    } 
    int num = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, num);
}
void sortInsert(stack<int> &s, int element) {
    if(s.empty() || (!s.empty() && s.top() < element)) {
        s.push(element);
        return;
    } 
    int num = s.top();
    s.pop();
    sortInsert(s, element);
    s.push(num);
}
void sortStack(stack<int> &s) {
    if(s.empty()) {
        return;
    }
    int num = s.top();
    s.pop();
    sortStack(s);
    sortInsert(s, num);
}
bool findRedundant(string str) {
    stack<char> st;
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (ch == '(' || ch =='+' || ch == '-' || ch == '/' || ch == '*') {
            st.push(ch);
        } else {
            if(ch == ')') {
                bool isRedundant = true;
                while(st.top() != '(') {
                    char top = st.top();
                    if(top == '+' || top == '-' || top == '/' || top == '*') {
                        isRedundant = false;
                    }
                    st.pop();
                    }
                    if(isRedundant == true) {
                        return true;
                    st.pop();
                }
            }
        }
    }
    return true;
}
int findMinimumCost(string str) {
    if((str.length())%2!=0) return -1;
    stack<char> st;
    for(int i = 0; i<str.length(); i++) {
        char ch = str[i];
        if(ch == '{') {
            st.push(ch);
        } else {
            //ch is closed bracket
            if(!st.empty() && st.top() == '{') {
                st.pop();
            } else {
                st.push(ch);
            }
        }
    }
    //Stack contains invalid expression
        int a = 0, b = 0;
        while(!st.empty()) {
            if(st.top() == '{') {
                b++;
            } else {
                a++;
            }
            st.pop();
        }
        int ans = (a+1)/2+(b+1)/2;
    return ans;
}
void nextSmaller(int* arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> result(n);
    for (int i = n - 1; i >= 0; i--) {
        while (s.top() != -1 && s.top() >= arr[i]) {
            s.pop();
        }
        result[i] = s.top();
        s.push(arr[i]);
    }
    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

void printingStack(stack<int> s) {
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
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

int main() {
    // string str = "Babbar";
    // stack<char> st;
    // for(int i = 0; i<str.length(); i++) {
    //     char ch = str[i];
    //     st.push(ch);
    // }
    // string ans = "";
    // while(!st.empty()) {
    //     char ch = st.top();
    //     ans.push_back(ch);
    //     st.pop();
    // }
    // cout << "Answer is -> " << ans << endl;
    // stack<int> s;
    // s.push(5);
    // s.push(9);
    // s.push(12);
    // s.push(8);
    // s.push(4);
    // int size = s.size();
    // int cnt = 0;
    // // deleteMiddle(s, cnt, size);
    // // printingStack(s);
    // insertAtBottom(s, cnt);
    // printingStack(s);
    // string parenthesis = "[({})]";
    // reverseStack(s);
    // printingStack(s);
    // sortStack(s);
    // printingStack(s);
    // string str1 = "((a+b))";
    // if(findRedundant(str1)) {
    //     cout << "String is not redundant" << endl;
    // } else {
    //     cout << "String is redundant" << endl;
    // }
    // // if(isValidParenthesis(parenthesis)) {
    // //     cout << "Statement is valid parenthesis " << endl;
    // // } else {
    // //     cout << "Statement is unvalid parenthesis " << endl;
    // // }
    // string str2 = "}}}}}{{{{{";
    // cout << "Find minimum cost-> " << findMinimumCost(str2) << endl;
    int arr1[] = {2, 1, 4, 3};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout << "Next smaller elements: ";
    nextSmaller(arr1, n);
    cout << largestRectangularArea(arr1, n);
    return 0;
}