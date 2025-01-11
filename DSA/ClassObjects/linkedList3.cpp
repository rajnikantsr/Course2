#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~node() {
        cout << "Node with value " << data << " is being deleted." << endl;
        next = NULL;  // Prevent recursive deletion
    }
};

// Insert at head
void insertAtHead(node*& head, node*& tail, int n) {
    node* temp = new node(n);
    temp->next = head;
    head = temp;
    if (tail == NULL) { // If the list was empty
        tail = head;
    }
}

// Insert at tail
void insertAtTail(node*& head, node*& tail, int n) {
    node* temp = new node(n);
    if (tail != NULL) {
        tail->next = temp;
    }
    tail = temp;
    if (head == NULL) { // If the list was empty
        head = tail;
    }
}

// Insert in the middle
void insertInMiddle(node*& head, node*& tail, int position, int n) {
    if (position == 1) {
        insertAtHead(head, tail, n);
        return;
    }

    node* temp = head;
    int count = 1;
    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL || temp->next == NULL) {
        insertAtTail(head, tail, n);
        return;
    }

    node* nodeToInsert = new node(n);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// Reverse the list in groups of k
node* reversingKthterm(node*& head, node*& tail, int k) {
    if (head == NULL || k <= 1) return head;

    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;

    int count = 0;

    // Reverse the first k nodes
    while (curr != NULL && count < k) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Update the head pointer for the current segment
    if (forward != NULL) {
        head->next = reversingKthterm(forward, tail, k);
    }

    // Update the tail pointer if this was the first segment
    if (tail == head || tail == prev) {
        tail = head;
    }

    return prev; // New head after reversal
}
bool checkCircular(node* &head) {
    if(head == NULL) {
        return true;
    } 
    node* temp = head->next;
    while(temp!=NULL && temp != head) {
        temp = temp->next;
    }
    if(temp == head) {
        return true;
    }
    return false;
}
// Print the linked list
void print(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    node* node1 = new node(10);
    node* head = node1;
    node* tail = node1;

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

    int k;
    cout << "Enter value for reversing list in Kth group: ";
    cin >> k;

    head = reversingKthterm(head, tail, k);
    print(head);

    cout << "Head: " << head->data << endl;
    cout << "Tail: " << tail->data << endl;
        if(checkCircular(head)){
        cout << "List is circular" << endl;
    } else {
        cout << "Not circular" << endl;
    }
    return 0;
}