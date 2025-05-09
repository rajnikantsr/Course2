#include <iostream>
#include <queue>
using namespace std;

// class Stack {
//     queue<int> q1, q2;

// public:
//     void push(int x) {
//         q2.push(x);
//         while (!q1.empty()) {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         swap(q1, q2);
//     }
//     void pop() {
//         if (q1.empty()) {
//             cout << "Stack Underflow\n";
//             return;
//         }
//         q1.pop();
//     }
//     int top() {
//         if (q1.empty()) {
//             cout << "Stack is empty\n";
//             return -1;
//         }
//         return q1.front();
//     }
//     bool empty() {
//         return q1.empty();
//     }
// };
#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1;

public:
    void push(int x) {
        int n = q1.size(); // Get the current size before modifying the queue
        q1.push(x);
        
        // Move all previous elements behind the new one to maintain stack order
        for (int i = 0; i < n; i++) {
            q1.push(q1.front());
            q1.pop();
        }
    }
    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        q1.pop();
    }
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
};
int main() {
    Stack s;
    s.push(3);
    s.push(4);
    s.push(2);
    s.push(1);
    cout << "Top: " << s.top() << endl; // Output: 1
    s.pop();
    cout << "Top: " << s.top() << endl; // Output: 2
    s.pop();
    cout << "Top: " << s.top() << endl; // Output: 4
    return 0;
}
