#include<iostream>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
    Node(int d) {
        this->data=d;
        this->next=NULL;
    }
    ~Node() {
        int value = this->data;
        if(this->next!=NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data : " << value << endl;
    }
};
void insertNode(Node* &tail, int element, int n) {
    if(tail == NULL) {
        Node* newNode = new Node(n);
        tail = newNode;
        newNode -> next = newNode;
    } else {
        //Assuming that element is present in the list
        Node* curr = tail;
        while(curr->data!=element) {
            curr = curr->next;
        }
        //Element found
        Node* temp = new Node(n);
        temp->next = curr->next;
        curr -> next = temp;
    }
}
void deleteNode(Node* &tail, int value) {
    if(tail == NULL) {//empty list
        cout << "List is empty " << endl;
        return;
    } else {//non empty list
        //Assuming list is non empty
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data!=value) {
            prev = curr;
            curr = curr->next;
        }
        if(curr == prev) {
            tail = NULL;
        }
        if(tail == curr) {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next=NULL;
    }
}
void print(Node* tail) {
    Node* temp = tail;
    if(tail == NULL) {
        cout << "Empty list" << endl;
        return ;
    }
    do{
        cout << tail->data << endl;
        tail = tail->next;
    } while(tail != temp) ;
    cout << "finished" << endl;
}
int main() {
    Node* tail = NULL;
    insertNode(tail, 3, 2);//tail -> element after which value is to insert-> value to insert
    print(tail);
    insertNode(tail, 2, 3);
    print(tail);
    insertNode(tail, 2, 5);
    print(tail);
    deleteNode(tail, 2);
    print(tail);
    return 0;
}