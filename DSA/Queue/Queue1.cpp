#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int qfront;
    int rear;
    int size;

public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return qfront == rear;
    }

    void enqueue(int data) {
        if (rear == size - 1) { 
            cout << "Queue is filled" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (qfront == rear) {
            return -1; 
        } else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;

            if (qfront == rear) { 
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() { 
        if (qfront == rear) {
            return -1;
        } else {
            return arr[qfront];
        }
    }
};
class circularQueue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    circularQueue(int n) { 
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    ~circularQueue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is full" << endl;
            return;
        }
        else if (front == -1) { 
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = value;  
    }

    int dequeue() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) { 
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
        return ans;
    }
};
class doubleEndedQueue {
    int *arr;
    int front;
    int rear;
    int size;
    public :
    doubleEndedQueue(int n) {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }
    ~doubleEndedQueue() {
        delete[] arr;
    }
    int pushFront(int d) {
        if(isFull()) {
            cout << "Queue is filled" << endl;
        } 
        else if(isEmpty()) {
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1) {
            front = size-1;
        } else {
            front++; 
        }
        arr[front] = d;
        return front;
    }
    int pushBack(int d) {
        if(isFull()) {
            cout << "Queue is full " << endl;
        } 
        else if(isEmpty()) {
            front = rear = 0;
        } 
        else if(rear == size-1 && front != 0) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = d;
        return front;
    }
    int popFront() {
        if(isEmpty()) {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear) {
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;
        } else {
            front++;
        }
        return ans;
    }
    int popRear() {
        if(isEmpty()) {
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if(front == rear) {
            front = rear = -1;
        }
        else if(rear == 0) {
            rear = size-1;
        } else {
            rear--;
        }
    }
    int getFront() {
        if(isEmpty()) {
            return -1;
        }
        return arr[front];
    }
    int getRear() {
        if(isEmpty()) {
            return -1;
        }
        return arr[rear];
    }
    bool isEmpty() {
        if(front == -1) {
            return true;
        }
        return false;
    }
    bool isFull() {
        if((front == 0 && rear == size-1) || (front!=0 && rear == (front-1)%(size-1))) {
            return true;
        } else {
            return false;
        }
    }
};
int main() {
    // Queue q;
    // q.enqueue(17);
    // q.enqueue(18);
    // q.enqueue(19);
    // q.enqueue(20);
    // q.enqueue(21);

    // while (!q.isEmpty()) {
    //     cout << q.front() << " ";
    //     q.dequeue();
    // }
    // cout << endl;
    // circularQueue r(5);
    // r.enqueue(17);
    // r.enqueue(18);
    // r.enqueue(19);
    // r.enqueue(20);
    // r.enqueue(21);

    // cout << "Dequeuing from circular queue: " << r.dequeue() << endl;
    doubleEndedQueue s(5);
    s.pushFront(1);
    s.pushFront(2);
    s.pushBack(3);
    s.pushBack(4);
    for(int i = 0; i<4; i++) {
        cout << s.getFront() << " ";
        s.popFront() ;
    }
    return 0;
}
