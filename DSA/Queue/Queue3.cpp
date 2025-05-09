#include <iostream>
#include<queue>
#include<stack>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

class solution {
public:
    int tour(petrolPump p[], int n) {
        int deficit = 0;
        int balance = 0;
        int start = 0;
        
        for (int i = 0; i < n; i++) {
            balance += p[i].petrol - p[i].distance;
            if (balance < 0) {
                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }
        return (deficit + balance >= 0) ? start : -1;
    }
};
// queue<int> interLeave(queue<int> q, int n) {
//     queue<int> newQ;
//     for(int i = 0; i<n/2; i++) {
//         newQ.push(q.front());
//         q.pop();
//     }
//     while(!newQ.empty()) {
//         int val = newQ.front();
//         newQ.pop();
//         q.push(val);
//         val = q.front();
//         q.pop();
//         q.push(val);
//     }
//     return q;
// }
queue<int> interLeave(queue<int> q, int n) {
    stack<int> s;
    int half = n/2;
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()) {
        int val = s.top();
        s.pop();
        q.push(val);
        val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}
int main() {
    // petrolPump arr[] = {{4, 6}, {6, 5}, {7, 3}, {4, 5}};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // solution sol;
    // int startIndex = sol.tour(arr, n);
    // if (startIndex != -1)
    //     cout << "Start at petrol pump: " << startIndex << endl;
    // else
    //     cout << "No possible tour." << endl;
    queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.push(6);
    int size = queue.size();
    queue = interLeave(queue, size);
    while(!queue.empty()) {
        cout << queue.front() << " ";
        queue.pop();
    }
    return 0;
}
