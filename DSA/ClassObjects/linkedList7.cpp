// #include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public :
    int data;
    Node* next;
    Node* random;
    Node(int x) {
        data = x;
        next = random = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int d) {
    Node* newNode = new Node(d);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return ;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
/*Node* cloneList(Node*head) {
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* temp = head;
    while(temp!=NULL) {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }
    unordered_map<Node*, Node*> oldToNewNode;
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    while(originalNode !=NULL) {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode ->next;
        cloneNode = cloneNode->next;
    }
    originalNode = head;
    cloneNode = cloneHead; 
    while(originalNode != NULL) {
        cloneNode->random = oldToNewNode[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}
*/

Node* cloneList(Node* &head) {
    //Step 1 : create a clone list
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    Node* temp = head;
    while(temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }
    //Step 2 : Add cloneNode between original Node
    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode!=NULL && cloneNode!=NULL) {
        Node* Next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = Next;
        Next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = Next;
    }
    //Step 3 : Linking of random pointer
    temp = head;
    while(temp != NULL) {
        if(temp->next != NULL) {
            temp -> next -> random = temp->random ? temp->random->next : temp->random;//temp->random true implies temp->next->random = temp->random->next if false then it will temp->random
            temp = temp->next->next;//On pointing random node then, to next node temp shifted to twice 
        }
    }
    //Step 4 : Revert changes made in step 2 
    originalNode = head;
    cloneNode = cloneHead;
    while(originalNode!=NULL && cloneNode!=NULL) {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;
        if(originalNode!=NULL) {
            cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    } 
    //Step 5 : Return ans
    return cloneHead;
}
// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << "(";
        if(head->random)
            cout << head->random->data << ")";
        else 
            cout << "null" << ")";
        
        if(head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    // Creating a linked list with random pointer
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;
    // Print the original list
    cout << "Original linked list:\n";
    printList(head);
    // Function call
    Node* clonedList = cloneList(head);
    cout << "Cloned linked list:\n";
    printList(clonedList);
    return 0;
}