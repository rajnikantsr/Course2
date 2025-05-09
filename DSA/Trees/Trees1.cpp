#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class node {
    public:
    int data;
    node* left;
    node* right;
    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
node* buildTree(node* root) {
    cout << "Enter the data " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if(data == -1) {
        return NULL;
    }
    cout << "Enter data for inserting in left" << endl;
    root->left = buildTree(root->left); 
    cout << "Enter data for inserting in right" << endl;
    root->right = buildTree(root->right);
}
void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        if(temp == NULL) {//Old level is completed
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if(temp->left) {//temp->left not null
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}
void reverseLevelOrderTraversal(node* root) {
    if (!root) return;
    queue<node*> q;
    stack<vector<int>> s; // Stack to store levels
    q.push(root);
    while (!q.empty()) {
        int size = q.size(); // Get number of nodes at the current level
        vector<int> level; // Store current level nodes
        for (int i = 0; i < size; i++) {
            node* temp = q.front();
            q.pop();
            level.push_back(temp->data);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        s.push(level); // Push level nodes into stack
    }
    // Print levels in reverse order
    while (!s.empty()) {
        vector<int> level = s.top();
        s.pop();
        for (int num : level) {
            cout << num << " ";
        }
        cout << endl;
    }
}
void buildFromLevelOrder(node* &root) {
    queue<node* > q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        cout << "Enter left node for: " << temp -> data << endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1) {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter right node for: " << temp -> data << endl;
        int rightData;
        cin >> rightData;
        if(rightData != -1) {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
void inOrderTraversal(node* root) {
    //Base Case 
    if(root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}
void PreOrderTraversal(node* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
}
void PostOrderTraversal(node* root) {
    if(root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
    cout << root -> data << " ";
}
void inOrderforLeaf(node* root, int &cnt) {
    if(root == NULL) {
        return;
    }
    inOrderforLeaf(root->left, cnt);
    if(root->left == NULL && root->right == NULL) {
        cnt++;
    }
    inOrderforLeaf(root->right, cnt);
}
int noOfLeafNode(node* root) {
    int cnt = 0;
    inOrderforLeaf(root, cnt);
    return cnt;
}
int main() {
    node* root = NULL;
    //Creating a tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // levelOrderTraversal(root);
    // reverseLevelOrderTraversal(root);
    // buildFromLevelOrder(root);
    // levelOrderTraversal(root); 
    cout << noOfLeafNode(root);
    return 0;
}
