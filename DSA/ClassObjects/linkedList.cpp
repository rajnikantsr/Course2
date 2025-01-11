#include <iostream>
using namespace std;

class linkedListNode {
public:
    int data;
    linkedListNode* Next;

    linkedListNode(int data) {
        // Constructor
        this->data = data;
        this->Next = NULL;
    }

    // Destructor
    ~linkedListNode() {
        int value = this->data;
        // Free memory
        if (this->Next != NULL) {
            delete Next;
            this->Next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertAtHead(linkedListNode*& Head, linkedListNode*& Tail, int n) {
    // Create a new node
    linkedListNode* temp = new linkedListNode(n);
    temp->Next = Head;
    Head = temp;
}

void insertAtTail(linkedListNode*& Head, linkedListNode*& Tail, int n) {
    linkedListNode* temp = new linkedListNode(n);
    if (Tail != NULL) {
        Tail->Next = temp;
    }
    Tail = temp;
    if (Head == NULL) {
        Head = Tail;
    }
}

void insertInMiddle(linkedListNode*& Head, linkedListNode*& Tail, int position, int n) {
    linkedListNode* temp = Head;
    if (position == 1) {
        insertAtHead(Head, Tail, n);
        return;
    }
    int cnt = 1;
    while (cnt < position - 1) {
        temp = temp->Next;
        cnt++;
    }
    // Inserting at last position
    if (temp->Next == NULL) {
        insertAtTail(Head, Tail, n);
        return;
    }
    // Create a node for n
    linkedListNode* nodeToInsert = new linkedListNode(n);
    nodeToInsert->Next = temp->Next;
    temp->Next = nodeToInsert;
}

void deleteNode(int position, linkedListNode*& head) {
    // Deleting the first node
    if (position == 1) {
        linkedListNode* temp = head;
        head = head->Next;
        delete temp;
        return;
    } else {
        // Deleting any middle or last node
        linkedListNode* curr = head;
        linkedListNode* prev = NULL;
        int cnt = 1;
        while (cnt < position) { // Fixed the condition here
            prev = curr;
            curr = curr->Next;
            cnt++;
        }
        prev->Next = curr->Next;
        curr->Next = NULL;
        delete curr;
    }
}

void print(linkedListNode*& Head) {
    linkedListNode* temp = Head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->Next;
    }
    cout << endl;
}

int main() {
    linkedListNode* node1 = new linkedListNode(10);
    linkedListNode* head = node1;
    linkedListNode* tail = node1;

    print(head);

    insertAtHead(head, tail, 12);
    print(head);

    insertAtHead(head, tail, 17);
    print(head);

    insertAtTail(head, tail, 14);
    print(head);

    insertAtTail(head, tail, 118);
    print(head);

    insertInMiddle(head, tail, 4, 19);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;

    deleteNode(2, head);
    print(head);
    return 0;
}