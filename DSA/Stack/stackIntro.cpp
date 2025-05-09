/*#include<iostream>
#include<stack>
using namespace std;
class Stack{
    //Properties
    public:
    int top;
    int *arr;
    int size;
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
            cout << arr[top] << endl;
        } else {
            cout << "Stack is overflow " << endl;
        }
    }
    void pop() {
        if(top>=0) {
            top--;
        } else {
            cout << "Stack is under flow " << endl;
        }
    }
    int peek() {
        if(top>=0) {
            return arr[top];
        } else {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
    bool isEmpty() {
        if(top == -1) {
            return true;
        } else {
            return false;
        }
    }
};
int main() {
    Stack st(3);
    st.push(12);
    st.push(13);
    st.push(12);
    st.push(17);
    cout << st.peek() << endl;
    // stack<int> s;
    // s.push(2);
    // s.push(3);
    // cout << "Printing top element-> " << s.top() << endl;
    // if(s.empty()) {
    //     cout << "Stack is empty " << endl;
    // } else {
    //     cout << "Stack size is " << s.size() << endl;
    //     }
    return 0;
}*/
#include<iostream>
#include<stack>
using namespace std;
class TwoStack{
    //Properties
    public:
    int top1;
    int top2;
    int *arr;
    int size;
    TwoStack(int s) {
        this -> size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }
    void push1(int element) {
        if(top2-top1 > 0) {
            top1++;
            arr[top1] = element;
            cout << arr[top1] << endl;
        } 
    }
    void push2(int element) {
        if(top2-top1 > 0) {
            top2--;
            arr[top2] = element;
            cout << arr[top2] << endl;
        } 
    }
    int pop1() {
        if(top1>=0) {
            int ans = arr[top1];
            top1--;
            return ans;
        } 
    }
    int pop2() {
        if(top2<size) {
            int ans = arr[top2];
            top2++;
            return ans;
        } else {
            return -1;
        }
    }
};
int main() {
    TwoStack st(6);
    st.push1(3);
    st.push2(3);
    st.push1(2);
    st.push2(5);
    st.push1(3);
    st.push2(3);
    st.pop2();
    return 0;
}