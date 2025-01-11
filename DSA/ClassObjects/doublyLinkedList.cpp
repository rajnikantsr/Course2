#include<iostream>
using namespace std;

class Node{
    public :
    int data;
    Node* next;
    Node* prev;
    Node(int d) {//Constructor
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node() {
        int value = this->data;
        if(next!=NULL) {
            delete next;
            next = NULL;

        }
        cout << "Memory is free for node with data : " << value << endl;
    }
};
void insertAtHead(Node* &tail, Node* &head, int n) {
    if(head == NULL) {
        Node* temp = new Node(n);
        head = temp;
        tail = temp;
    } else {
        Node* temp = new Node(n);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    
}
void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}
void insertAtTail(Node* &tail, Node* &head, int n) {
    if(tail == NULL) {
        Node* temp = new Node(n);
        tail = temp;
        head = temp;
    } else {
        Node* temp = new Node(n);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node* &tail, Node* &head, int position, int n) {
    if(position == 1) {
        insertAtHead(tail, head, n);
        return ;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL) {
        insertAtTail(tail, head, n);
        return ;
    }
    Node* nodeToInsert = new Node(n);
    nodeToInsert->next = temp->next; 
    temp -> next -> prev = nodeToInsert->next;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}
void deleteNode(Node* &tail, Node* &head, int position) {
    if(position == 1) {
    Node* temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;
    delete temp;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if(curr->next == NULL) { // deleting last node
            tail = curr->prev;
            if(tail != NULL)
                tail->next = NULL;
            else
                head = NULL;
        }

        curr -> prev = NULL;
        prev -> next = curr->next;
        curr -> next = NULL;
        delete curr; 
    }
}
int getLength(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp!=NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
int main() {
    // Node* node1 = new Node(10);
    // Node* head = node1;
    // Node* tail = node1;
    Node* head = NULL;
    Node* tail = NULL;
    print(head);
    // cout << getLength(head) << endl;
    insertAtHead(tail, head, 11);
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    insertAtHead(tail, head, 13);
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    insertAtHead(tail, head, 8);
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    insertAtTail(tail, head, 25);
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    insertAtPosition(tail, head, 5, 100);
    print(head);
    deleteNode(tail, head, 5);
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    return 0;
}