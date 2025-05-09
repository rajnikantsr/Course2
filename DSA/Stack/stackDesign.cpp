// #include <iostream>
// #include <stack>
// #include<climits>
// using namespace std;
// class MinStack {
//     stack<int> s, minStack;
//     public:
//     void push(int x) {
//         s.push(x);
//         if (minStack.empty() || x <= minStack.top()) {
//             minStack.push(x);
//         }
//     }
//     void pop() {
//         if (s.empty()) return;
//         if (s.top() == minStack.top()) {
//             minStack.pop();  
//         }
//         s.pop();
//     }
//     int getMin() {
//         if (minStack.empty()) return INT_MAX;
//         return minStack.top();
//     }
// };
// int main() { 
//     MinStack s;
//     int n, x;
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> x;
//         s.push(x);
//     }
//     cout << s.getMin() << endl;
//     return 0;
// }


#include <iostream>
#include <stack>
#include <climits>

using namespace std;

class MinStack {
    stack<int> s, minStack;
public:
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }
    void pop() {
        if (s.empty()) return;
        if (s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop();
    }
    int getMin() {
        if (minStack.empty()) {
            cout << "Stack is empty, no minimum element." << endl;
            return INT_MAX;
        }
        return minStack.top();
    }
};

class specialMinStack {
    stack<int> s;
    int mini;
public:
    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        } else {
            if (data < mini) {
                s.push(2 * data - mini);
                mini = data;
            } else {
                s.push(data);
            }
        }
    }
    int pop() {
        if (s.empty()) {
            cout << "Stack is empty, cannot pop." << endl;
            return -1;
        }
        int curr = s.top();
        s.pop();
        if (curr > mini) {
            return curr;
        } else {
            int prevMin = mini;
            mini = 2 * mini - curr;
            return prevMin;
        }
    }
    int top() {
        if (s.empty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        int curr = s.top();
        return (curr < mini) ? mini : curr;
    }
    bool isEmpty() {
        return s.empty();
    }
    int getMin() {
        if (s.empty()) {
            cout << "Stack is empty, no minimum element." << endl;
            return -1;
        }
        return mini;
    }
};

int main() {
    MinStack s;
    int n, x;
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> x;
        s.push(x);
    }
    cout << s.getMin() << endl;
    specialMinStack st;
    int m, y;
    cout << "Enter the number of elements: ";
    cin >> m;
    cout << "Enter " << m << " elements: ";
    for (int i = 0; i < m; i++) {
        cin >> y;
        st.push(y);  // ✅ Corrected 's.push(y)' to 'st.push(y)'
    }
    cout << "Minimum element from stack -> " << st.getMin() << endl;
    return 0;
}