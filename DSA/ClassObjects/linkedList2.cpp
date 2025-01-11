#include <iostream>
using namespace std;

class linkedListNode {
public:
    int data;
    linkedListNode* Next;
    linkedListNode(int data) {
        this->data = data;
        this->Next = NULL;
    }
    ~linkedListNode() {
        int value = this->data;
        if (this->Next != NULL) {
            delete Next;
            this->Next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertAtHead(linkedListNode*& Head, linkedListNode*& Tail, int n) {
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
    if (temp->Next == NULL) {
        insertAtTail(Head, Tail, n);
        return;
    }
    linkedListNode* nodeToInsert = new linkedListNode(n);
    nodeToInsert->Next = temp->Next;
    temp->Next = nodeToInsert;
}

// linkedListNode* reverseList(linkedListNode*& Head, linkedListNode*& Tail) {
//     if (Head == NULL || Head->Next == NULL) {
//         return Head;
//     }
//     linkedListNode* prev = NULL;
//     linkedListNode* curr = Head;
//     linkedListNode* forward = NULL;
//     while (curr != NULL) {
//         forward = curr->Next;
//         curr->Next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     Tail = Head;  // Update the tail to the original head after reversal
//     Head = prev;  // Return the new head (prev)
// }
//Reversing linked list using pointer
// void reverseList(linkedListNode* &Head, linkedListNode* &Tail, linkedListNode* &prev, linkedListNode* &curr) {
//     if (curr == NULL) {
//         Tail = Head;
//         Head = prev;
//         return;
//     }
//     linkedListNode* forward = curr->Next;
//     curr->Next = prev; 
//     reverseList(Head, Tail, curr, forward);
// }
//Reversing linkedlist using recursion app 2
linkedListNode* reverseList(linkedListNode* &Head, linkedListNode* &Tail) {
    linkedListNode* temp = Head;
    if (Head == NULL || Head->Next == NULL) {
        return Head;
    }
    linkedListNode* newHead = reverseList(Head->Next, Tail);
    Head->Next->Next = Head;
    Head->Next = NULL;
    Tail = Head;
    return newHead;
}

void print(linkedListNode*& Head) {
    if (Head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    linkedListNode* temp = Head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->Next;
    }
    cout << endl;
}
// int getLength(linkedListNode* &Head) {
//     linkedListNode* temp = Head;
//     int cnt = 0;
//     while(temp != NULL) {
//         cnt++;
//         temp = temp->Next;
//     }
//     return cnt;
// }

// linkedListNode* getMiddle(linkedListNode* &Head) {
//     int length = getLength(Head);
//     int ans = length/2, cnt = 0;
//     linkedListNode* temp = Head;
//     while(cnt < ans) {
//         temp = temp->Next;
//         cnt++;
//     }
//     return temp;
// }
////Approach 2 for getMiddle
linkedListNode *getMiddle(linkedListNode *head){

    //if the list has no nodes or a single node
    if(head==NULL || head->Next==NULL){
        return head;
    }

    linkedListNode *slow=head;
    linkedListNode *fast=head;

    while(fast!=NULL && fast->Next!=NULL){
        slow=slow->Next;
        fast=fast->Next->Next;
    }
    return slow;
}
int main() {
    linkedListNode* node1 = new linkedListNode(10);
    linkedListNode* head = node1;
    linkedListNode* tail = node1;
    insertAtHead(head, tail, 12);
    insertAtHead(head, tail, 17);
    insertAtTail(head, tail, 14);
    insertAtTail(head, tail, 118);
    insertInMiddle(head, tail, 4, 19);
    // cout << "Original list: ";
    // print(head);
    // cout << "Head: " << head->data << endl;
    // cout << "Tail: " << tail->data << endl;
    // head = reverseList(head, tail);
    // cout << "Reversed list: ";
    // print(head);
    // cout << "Head: " << head->data << endl;
    // cout << "Tail: " << tail->data << endl;
    linkedListNode* middle = getMiddle(head);
    cout << middle->data << endl;
    return 0;
}
