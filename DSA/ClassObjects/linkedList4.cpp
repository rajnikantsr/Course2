#include<iostream>
#include<map>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data: " << value << endl;
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
    if(tail == NULL) {
        cout << "List is empty " << endl;
        return;
    }
    Node* prev = tail;
    Node* curr = prev->next;
    while(curr->data != value) {
        prev = curr;
        curr = curr->next;
        if(curr == tail) {
            cout << "Value not found in the list" << endl;
            return;
        }
    }
    if(curr == prev) {
        tail = NULL;
    } else {
        prev->next = curr->next;
        if(tail == curr) {
            tail = prev;
        }
    }
    curr->next = NULL;
    delete curr;
}

bool checkCircular(Node* &head) {
    if(head == NULL) {
        return false;
    }
    Node* temp = head->next;
    while(temp != NULL && temp != head) {
        temp = temp->next;
    }
        if(temp == head) {
        return head;
    }
    return false;
}

bool detectLoop(Node* head) {
    if(head == NULL) return false;
    map<Node*, bool> visited;
    Node* temp = head;
    while(temp != NULL) {
        if(visited[temp] == true) {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

void print(Node* tail) {
    if(tail == NULL) {
        cout << "Empty list" << endl;
        return;
    }
    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while(temp != tail);
    cout << endl;
}

int main() {
    Node* tail = NULL;
    insertNode(tail, 3, 2); // Initial insertion
    print(tail);
    insertNode(tail, 2, 3);
    print(tail);
    insertNode(tail, 2, 5);
    print(tail);

    if(checkCircular(tail)) {
        cout << "List is circular" << endl;
    } else {
        cout << "Not circular" << endl;
    }

    if(detectLoop(tail)) {
        cout << "Loop is detected" << endl;
    } else {
        cout << "Loop is not detected" << endl;
    }

    deleteNode(tail, 2);
    print(tail);

    return 0;
}