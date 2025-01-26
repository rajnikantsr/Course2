#include <iostream>
#include <map>
#include<vector>
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
    if(Head == NULL) {
        Head = temp;
        Tail = temp;
        return;
    } else {
        Tail -> next = temp;
        Tail = temp;
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
Node* sortList(Node*& head, Node*& tail) {
    if (head == NULL || head->next == NULL) return head;
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node* temp = head;
    while(temp!=NULL) {
        if(temp->data == 0) zeroCount++;
        else if(temp->data == 1) oneCount++;
        else twoCount++;
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL) {
        if(zeroCount > 0) {
            temp->data = 0;
            zeroCount--;
        } else if(oneCount > 0) {
            temp->data = 1;
            oneCount--;
        } else {
            temp->data = 2;
        }
        temp = temp->next;
    }
    return head;
}
Node* SortList(Node* &head, Node* &tail) {
    if(head == NULL || head->next == NULL) return head;
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;
    Node* curr = head;
    while(curr != NULL) {
        int value = curr->data;
        if(value == 0) {
            insertAtTail(zeroHead, zeroTail, value); 
        } else if(value == 1) {
            insertAtTail(oneHead, oneTail, value);
        } else {
            insertAtTail(twoHead, twoTail, value);
        }
        curr = curr->next;
    }
    if(oneHead->next != NULL) {
        zeroTail->next = oneHead->next;
    } else {
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}
Node* solve(Node* &head1, Node* &head2) {
    //If only one element is present in head1
    if(head1->next == NULL) {
        head1->next = head2;
        return head1;
    }
    Node* curr = head1;
    Node* forw = curr->next;
    Node* temp = head2;
    Node* tempNext = temp->next;
    while(forw != NULL && head2 != NULL) {
        if(temp->data >= curr->data && temp->data <= forw->data) {
            //Adding Nodes
            curr->next = temp;
            tempNext = temp->next;
            //Updating pointer
            temp->next = forw;
            curr = temp;
            temp = tempNext;
        } else {
            //second list mai aage point karana padega
            curr = forw;
            forw = forw->next;
            if(forw == NULL) {
                curr -> next = temp; 
                return head1;
            } 
        }
    }
    return head1;
}
Node* mergeTwolist(Node* &head1, Node* & head2) {
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    if(head1->data <= head2->data) {
        head1 = solve(head1, head2);
    } else {
        head1 = solve(head2, head1);
    }
    return head1;
}
void print(Node* head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
bool checkPalindrome(vector<int> arr) {
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while(s<=e) {
        if(arr[s] != arr[e]) {
            return 0;
        } 
        s++;
        e--;
    }
    return 1;
}
bool isPalindrome(Node* head) {
    vector<int> arr;
    Node* temp = head;
    while(temp!=NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return checkPalindrome(arr);
}
Node* getMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* forw = NULL;
    while(curr!=NULL) {
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }
    return prev;
}
bool IsPalindrome(Node* &head) {
    if(head == NULL || head->next == NULL) {
        return true;
    }
    Node* middle = getMid(head);
    //Reversing list after middle
    Node* temp = middle->next;
    middle->next = reverse(temp);
    //Comparing both halves
    Node* head1 = head;
    Node* head2 = middle->next;
    while(head2 != NULL) {
        if(head1->data != head2->data) {
            return 0;
        } 
        head1 = head1->next;
        head2 = head2->next;
    }
    temp = middle->next;
    middle->next = reverse(temp);
    return 1;
}
/*
Node* add(Node* first, Node* second) {
    int carry = 0;
    Node* headAns = NULL;
    Node* tailAns = NULL;
    while(first != NULL && second != NULL) {
        int sum = carry + first->data + second->data;
        int digit = sum%10;
        Node* temp = new Node(digit);
        insertAtTail(headAns, tailAns, digit);
        carry = sum/10;
        first = first->next;
        second = second->next;
    }
    while(first != NULL) {
        int sum = carry + first->data;
        int digit = sum%10;
        insertAtTail(headAns, tailAns, digit);
        carry = sum/10;
        first = first->next;
    }
    while(second != NULL) {
        int sum = carry + second -> data;
        int digit = sum%10;
        insertAtTail(headAns, tailAns, digit);
        carry = sum/10;
        second = second->next;
    }
    while(carry!=0) {
        int sum = carry;
        int digit = sum%10;
        insertAtTail(headAns, tailAns, digit);
        carry = sum/10;
    }
    return headAns;
}
*/
Node* add(Node* first, Node* second) {
    int carry = 0;
    Node* headAns = NULL;
    Node* tailAns = NULL;
    while(first != NULL || second != NULL || carry != 0) {
        int val1 = 0;
        if(first!=NULL) 
        val1 = first->data;
        int val2 = 0;
        if(second!=NULL)
        val2 = second->data;
        int sum = carry + val1 + val2;
        int digit = sum%10;
        Node* temp = new Node(digit);
        insertAtTail(headAns, tailAns, digit);
        carry = sum/10;
        if(first!=NULL)
            first = first->next;
        if(second!=NULL)
            second = second->next;
    }
    return headAns;
}
Node* addTwoList(Node* head, Node* temp2Head) {
    if(head == NULL) {
        return temp2Head;
    } 
    if(temp2Head == NULL) {
        return head;
    }
    Node* first = reverse(head);
    Node* second = reverse(temp2Head);
    Node* ans = add(first, second);
    ans = reverse(ans);
    return ans;
}
int main() {
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 0);    
    insertAtHead(head, tail, 0);
    insertAtTail(head, tail, 2);
    insertInMiddle(head, tail, 5, 2);
    insertInMiddle(head, tail, 3, 1);
    print(head);
    // sortList(head, tail);
    // SortList(head, tail);
    // Node* tempList = new Node(3);
    // Node* tempHead = tempList;
    // Node* tempTail = tempList;
    // insertAtHead(tempHead, tempTail, 2);
    // insertAtHead(tempHead, tempTail, 1);
    // print(tempHead);
    // mergeTwolist(head, tempHead);
    // print(head);
    Node* temp2List = new Node(1);
    Node* temp2Head = temp2List;
    Node* temp2Tail = temp2List;
    insertAtHead(temp2Head, temp2Tail, 2);
    insertAtHead(temp2Head, temp2Tail, 3);
    print(temp2Head);
    // if(isPalindrome(temp2Head)) {
    //     cout << "List is palindrome " << endl;
    // } else {
    //     cout << "Not palindrome " << endl;
    // }
    //Approach 2
    // if(IsPalindrome(temp2Head)) {
    //     cout << "List is palindrome " << endl;
    // } else {
    //     cout << "Not palindrome " << endl;
    // }
    Node* dummy = addTwoList(head, temp2Head);
    print(dummy);
}