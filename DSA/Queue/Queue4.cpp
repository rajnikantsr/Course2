#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class kQueue {
    public:
    int n;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freeSpot;
    int *next;
    public:
    kQueue(int n, int k) {
        this -> n = n;
        this -> k = k;
        front = new int[k];
        rear = new int[k];
        for(int i = 0; i<k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[n];
        for(int i = 0; i<n; i++) {
            next[i] = i+1;
        } 
        next[n-1] = -1;
        arr = new int[n];
        freeSpot = 0;
    }
    void enqueue(int data, int qn) {
        //Overflow
        if(freeSpot == -1) {
            cout << "no Empty space is present" << endl;
            return;
        }
        //Find first free index
        int index = freeSpot;
        //Update freeSpot
        freeSpot = next[index];
        //Check whether first element
        if(front[qn-1] == -1) {
            front[qn-1] = index;
        } else {
            //Link new element to the prev element
            next[rear[qn-1]] = index;
        }
        //Update next
        next[index] = -1;
        //Update rear
        rear[qn-1] = index; 
        //Push element
        arr[index] = data;
    }
    int dequeue(int qn) {
        // Underflow
        if (front[qn - 1] == -1) {
            cout << "Queue underflowed" << endl;
            return -1;  // Return an error value
        }
        // Find index
        int index = front[qn - 1];
        // Front shift forward
        front[qn - 1] = next[index];
        // Manage FreeSpot
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }     
};
vector<int> sumOfMaxMin(int *arr, int n, int k) {
    vector<int> ans;
    
    for(int i = 0; i <= n - k; i++) {  
        int maxVal = INT_MIN, minVal = INT_MAX;  
        for(int j = i; j < i + k; j++) {
            if(arr[j] < minVal) {
                minVal = arr[j];
            }
            if(arr[j] > maxVal) {
                maxVal = arr[j];
            }
        }
        ans.push_back(maxVal + minVal);
    }
    return ans;
}
int main() {
    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    int arr[] = {2, 5, -1, 7, -3, -1, -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    vector<int> temp = sumOfMaxMin(arr, n, 4);
    for(int val : temp) {
        cout << val << " ";
    }
    return 0;
}