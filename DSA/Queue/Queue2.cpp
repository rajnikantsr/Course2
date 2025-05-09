#include <iostream>
#include <queue>
#include <stack>
#include<deque>
#include<vector>
#include<unordered_map>
using namespace std;

void getReverse(queue<int>& q, int size) {
    stack<int> s;
    for(int i = 0; i < size; i++) {
        s.push(q.front());
        q.pop();
    }
    for(int i = 0; i < size; i++) {
        q.push(s.top());
        s.pop();
    }
}
void GetReverse(queue<int>& q) {
    if(q.empty()) {
        return;
    }
    int front = q.front();
    q.pop();
    GetReverse(q);
    q.push(front);
}
void print(queue<int> q) {  
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}
vector<long long int> getFirstNegative(int *arr, int n, int k) {
    vector<long long int> ans;
    deque<long long int> dq;
    //Process for first window
    for(int i = 0; i<k; i++) {
        if(arr[i] < 0) {
            dq.push_back(i);
        }
    }
    //Store answer of first window
    if(dq.size() > 0) {
        ans.push_back(arr[dq.front()]);
    } else {
        ans.push_back(0);
    }
    //Process the remaining part
    for(int i = k; i<n; i++) {
        //Removal
        if(!dq.empty() && i-dq.front() >= k) {
            dq.pop_front();
        }
        //Addition
        if(arr[i] < 0) {
            dq.push_back(i);
        }
        if(dq.size() > 0) {
            ans.push_back(arr[dq.front()]);
        } else {
            ans.push_back(0);
        }
    }
    return ans;
}
vector<long long int> GetFirstNegative(int *arr, int n, int k) {
    vector<long long int> ans;
    int firstNegIndex = 0;  // Pointer to track the first negative element in the window

    // Process each window
    for (int i = k - 1; i < n; i++) {
        // Move firstNegIndex to stay within the window
        while (firstNegIndex < i && (firstNegIndex <= i - k || arr[firstNegIndex] >= 0)) {
            firstNegIndex++;
        }

        // Store the first negative number or 0 if none exists
        ans.push_back((arr[firstNegIndex] < 0) ? arr[firstNegIndex] : 0);
    }

    return ans;
}
queue<int> reverseKelement(queue<int> q, int k, int n) {
    if (k > n || k <= 0) {
        cout << "Invalid k value!" << endl;
        return q;
    }
    stack<int> s;
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < n - k; i++) {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    return q;
}
string FirstNonRepeating(string str) {
    unordered_map<char, int> count;
    queue<int> q;
    string ans = "";
    for(int i = 0; i<str.length(); i++) {
        char ch = str[i];
        //Increase count
        count[ch]++;
        //push inside Queue 
        q.push(ch);
        while(!q.empty()) {
            if(count[q.front()] > 1) {
                q.pop();
            } else {
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()) 
            ans.push_back('#');
    }
    return ans;
}
int main() {
    // queue<int> q;
    // int n;
    // cout << "Enter number of elements you want to insert in queue: -> " ;
    // cin >> n;
    // cout << "Enter elements: -> ";
    // for(int i = 0; i < n; i++) {
    //     int temp;
    //     cin >> temp;
    //     q.push(temp);
    // }
    // cout << "Reversed queue: ";
    // getReverse(q, n);
    // print(q);
    // GetReverse(q);
    // print(q);
    cout << endl;
    int arr[] = {-8, 2, 3, -6, 10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    // cout << "SIze of window is 2" << endl;
    // vector<long long int> ans = getFirstNegative(arr, size, k);
    // for(long long num : ans) {
    //     cout << num << " ";
    // }
    // cout << endl;
    // vector<long long int> ans = GetFirstNegative(arr, size, k);
    // for(long long num : ans) {
    //     cout << num << " ";
    // }
    cout << endl;
    queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    int l = 3;
    // cout << "Value for reversing first l part i.e 3" << endl;
    // queue = reverseKelement(queue, l, 5);
    // while(!queue.empty()) {
    //     cout << queue.front() << " ";
    //     queue.pop();
    // }
    string str = "";
    string temp = FirstNonRepeating(str);
    cout << temp;
    return 0;
}
