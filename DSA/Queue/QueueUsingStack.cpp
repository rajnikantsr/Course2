#include <iostream>
#include <stack>
using namespace std;

// class Queue {
//     stack<int> s1, s2;

// public:
//     // Push element to the back of the queue
//     void push(int x) {
//         // Move all elements from s1 to s2
//         while (!s1.empty()) {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         // Push new element into s1
//         s1.push(x);
//         // Move all elements back from s2 to s1
//         while (!s2.empty()) {
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }
//     // Remove the front element
//     void pop() {
//         if (s1.empty()) {
//             cout << "Queue is underflowed" << endl;
//             return;
//         }
//         s1.pop();
//     }
//     // Get the front element
//     int top() {
//         if (s1.empty()) {
//             cout << "Queue is underflowed" << endl;
//             return -1;
//         }
//         return s1.top();
//     }
//     // Check if queue is empty
//     bool empty() {
//         return s1.empty();
//     }
// };
#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> input, output;

public:
    // Push element to the back of the queue
    void push(int x) {
        input.push(x);
    }

    // Remove the front element
    void pop() {
        if (output.empty()) {
            // Move elements from input to output only if output is empty
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        if (!output.empty()) {
            output.pop();
        } else {
            cout << "Queue is underflowed" << endl;
        }
    }

    // Get the front element
    int top() {
        if (output.empty()) {
            // Move elements from input to output only if output is empty
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        if (!output.empty()) {
            return output.top();
        } else {
            cout << "Queue is underflowed" << endl;
            return -1;
        }
    }

    // Check if the queue is empty
    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    Queue q;
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);

    cout << "Front element: " << q.top() << endl; // Output: 4
    q.pop();
    cout << "Front element after pop: " << q.top() << endl; // Output: 3

    return 0;
}
