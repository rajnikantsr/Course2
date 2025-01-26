#include <iostream>
#include <map>
#include <set>
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
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for node with data: " << value << endl;
    }
};

void insertAtHead(Node*& Head, Node*& Tail, int n) {
    Node* temp = new Node(n);
    temp->next = Head;
    Head = temp;
    if (Tail == NULL) {
        Tail = Head;
    }
}

void insertAtTail(Node*& Head, Node*& Tail, int n) {
    Node* temp = new Node(n);
    if (Tail != NULL) {
        Tail->next = temp;
    }
    Tail = temp;
    if (Head == NULL) {
        Head = Tail;
    }
}

void insertInMiddle(Node*& Head, Node*& Tail, int position, int n) {
    Node* temp = Head;
    if (position == 1) {
        insertAtHead(Head, Tail, n);
        return;
    }
    int cnt = 1;
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL || temp->next == NULL) {
        insertAtTail(Head, Tail, n);
        return;
    }
    Node* nodeToInsert = new Node(n);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// void deleteNode(int position, Node*& head) {
//     if (head == NULL) return; // Edge case: Empty list

//     // Deleting the first node
//     if (position == 1) {
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//         return;
//     } else {
//         // Deleting any middle or last node
//         Node* curr = head;
//         Node* prev = NULL;
//         int cnt = 1;
//         while (cnt < position && curr != NULL) {
//             prev = curr;
//             curr = curr->next;
//             cnt++;
//         }
//         if (curr == NULL) return; // Invalid position
//         prev->next = curr->next;
//         curr->next = NULL;
//         delete curr;
//     }
// }
/*Code for removing duplicates in sorted list having segmentation fault 
// Node* removeDuplicate(Node*& head, Node*& tail) {
//     if (head == NULL || head->next == NULL) return NULL;

//     Node* curr = head;
//     while (curr != NULL && curr->next != NULL) {
//         if (curr->data == curr->next->data) {
//             Node* nodeToDelete = curr->next;
//             curr->next = curr->next->next;
//             if (nodeToDelete == tail) {
//                 tail = curr; // Update tail if needed
//             }
//             delete nodeToDelete;
//         } else {
//             curr = curr->next;
//         }
//     }
//     return head;
// }
*/
Node* removeDuplicate(Node*& head, Node*& tail) {
    if (head == NULL || head->next == NULL) return head;

    Node* prev = head;
    Node* temp = prev->next;
    while(temp!=NULL) {
        if(temp->data == prev->data) {
            temp = temp->next;
            continue;
        }
        prev->next = temp;
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    return head;
}

//Remove duplicates from unsorted linkedList
// Node* removeduplicates(Node* &head, Node* &tail) {
//     if(head == NULL || head->next == NULL) return head;
//     Node* curr = head;
//     while(curr!=NULL || curr->next!=NULL) {
//         Node* temp = curr->next;
//         while(temp->next!=NULL) {
//             if(curr->data == temp->next->data) {
//                 Node* nodeToDelete = temp->next;
//                 temp->next = temp->next->next;
//                 // if (nodeToDelete == tail) {
//                 // tail = temp; // Update tail if needed
//                 // }
//                 delete nodeToDelete;
//             } else {
//                 temp = temp->next;
//             }
//         }
//         curr = curr->next;
//     }
//     return head;
// }
Node* removeduplicates(Node* head, Node* tail) {
        if (head == NULL || head->next == NULL) return head;
        
        set<int> seen;  // To store the values of the nodes
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->next!= NULL) {
            if (seen.find(current->data) != seen.end()) {
                // Duplicate found, skip the node
                prev->next = current->next;
                if(current->next == NULL) {
                    tail = current;
                }
                delete current;  // Free the memory of the duplicate node
            } else {
                // Add value to set and update prev
                seen.insert(current->data);
                prev = current;
            }
            current = prev->next;
            tail = prev;
            // tail = current;
        }

        return head;
    }
void print(Node*& Head) {
    if (Head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = Head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);
    insertAtTail(head, tail, 12);
    insertInMiddle(head, tail, 5, 12);

    cout << "Original list: ";
    print(head);
    cout << "Head of list is->" << head->data << endl;
    cout << "Tail of list ->" << tail->data << endl;

    // removeDuplicate(head, tail);

    // cout << "List after removing duplicates: ";
    // print(head);
    cout << "Head of list is->" << head->data << endl;
    cout << "Tail of list ->" << tail->data << endl;
    removeduplicates(head, tail);
    print(head);
    cout << "Head of list is->" << head->data << endl;
    cout << "Tail of list ->" << tail->data << endl;
    return 0;
}