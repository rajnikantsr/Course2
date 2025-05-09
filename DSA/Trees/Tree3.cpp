#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <map>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build a tree
node* buildTree(node* root) {
    cout << "Enter the data (-1 for NULL): ";
    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    root = new node(data);
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;  // Fix: Ensure the constructed tree is returned
}

// Function to perform ZigZag traversal
vector<int> ZigZagTraversal(node* root) {
    vector<int> result;
    if (root == NULL) return result;
    queue<node*> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty()) {
        int size = q.size();
        vector<int> ans(size);
        // Level processing
        for (int i = 0; i < size; i++) {
            node* frontNode = q.front();
            q.pop();
            // Insert in the correct position
            int index = leftToRight ? i : (size - 1 - i);
            ans[index] = frontNode->data;
            // Push children into queue
            if (frontNode->left) 
                q.push(frontNode->left);
            if (frontNode->right) 
                q.push(frontNode->right);
        }
        leftToRight = !leftToRight;  // Toggle the order
        // Append the level result to the final result
        for (auto i : ans) {
            result.push_back(i);
        }
    }
    return result;
}
void traverseLeft(node* root, vector<int>& ans) {
    //Base case
    if(root == NULL || root->left == NULL && root->right == NULL) return ;
    ans.push_back(root->data);
    if(root->left != NULL) {
        traverseLeft(root->left, ans);
    } else {
        traverseLeft(root->right, ans);
    }
}
void traverseLeaf(node* root, vector<int>& ans) {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}
void traverseRight(node* root, vector<int>& ans) {
    if(root == NULL || (root->left == NULL && root->right == NULL)) return;
    if(root->right != NULL) {
        traverseRight(root->right, ans);
    } else {
        traverseRight(root->left, ans); // FIXED
    }
    ans.push_back(root->data); // Add after recursion for bottom-up order
}
vector<int> boundaryTraversal(node* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    ans.push_back(root->data);
    //LeftBoundary
    traverseLeft(root->left, ans);
    traverseLeaf(root, ans);
    //Right Boundary
    traverseRight(root->right, ans);
    return ans;
}
vector<int> verticalTraversal(node* root) {
    map<int, map<int, vector <int>>> nodes;
    queue<pair<node*, pair<int, int>>> q;
    vector<int> ans;
    if(root == NULL) {
        return ans;
    }
    q.push(make_pair(root, make_pair(0, 0)));
    while(!q.empty()) {
        pair<node*, pair<int, int>> temp = q.front();
        q.pop();
        node* frontNode = temp.first;;
        int HD = temp.second.first;
        int level = temp.second.second;
        nodes[HD][level].push_back(frontNode->data);
        if(frontNode->left) {
            q.push(make_pair(frontNode->left, make_pair(HD-1, level+1)));
        }
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, make_pair(HD+1, level+1)));
        }
    }
    for(auto i : nodes) {
        for(auto j : i.second) {
            for(auto k : j.second) {
                ans.push_back(k);
            }
        }
    }
    return ans;
}
vector<int> topViewTraversal(node* root) {
    vector<int> ans;
    if(root == NULL) 
        return ans;
    map<int, int> topNode;
    queue<pair<node*, int>> q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
        pair<node*, int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int HD = temp.second;
        if(topNode.find(HD) == topNode.end()) {//Check if HD is already present in map or not 
            topNode[HD] = frontNode->data;
        }
        if(frontNode->left)
            q.push(make_pair(frontNode->left, HD-1));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, HD+1));
    }
    for(auto i : topNode) {
        ans.push_back(i.second);
    }
    return ans;
}
vector<int> bottomViewTraversal(node* root) {
    vector<int> ans;
    if(root == NULL) 
        return ans;
    map<int, int> bottomNode;
    queue<pair<node*, int>> q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
        pair<node*, int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int HD = temp.second;
        bottomNode[HD] = frontNode->data; // Update the bottom view with the latest node at this HD
        if(frontNode->left)
            q.push(make_pair(frontNode->left, HD-1));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, HD+1));
    }
    for(auto i : bottomNode) {
        ans.push_back(i.second);
    }
    return ans;
}
// Function to find the left view of the binary tree
void solve(node* root, vector<int>& ans, int level) {
    if (root == NULL) return;
    if (level == ans.size()) {
        ans.push_back(root->data);
    }
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}
vector<int> leftView(node* root) {
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}
// Function to find the right view of the binary tree
void Solve(node* root, vector<int>& ans, int level) {
    if (root == NULL) return;
    if (level == ans.size()) {
        ans.push_back(root->data);
    }
    Solve(root->right, ans, level + 1);
    Solve(root->left, ans, level + 1);
    
}
vector<int> rightView(node* root) {
    vector<int> ans;
    Solve(root, ans, 0);
    return ans;
}
vector<int> diagonalTraversal(node* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    map<int, vector<int>> diag;
    queue<pair<node*, int>> q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
        pair<node*, int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int HD = temp.second;
        diag[HD].push_back(frontNode->data);
        if(frontNode->left) {
            q.push(make_pair(frontNode->left, HD+1));
        }
        if(frontNode->right) {
            q.push(make_pair(frontNode->right, HD));
        }
    }
    for(auto i : diag) {
        for(auto j : i.second) {
            ans.push_back(j);
        }
    }
}
int main() {
    node* root = NULL;
    root = buildTree(root);
    // vector<int> BT1 = ZigZagTraversal(root);
    // cout << "ZigZag Traversal: ";
    // for (auto i : BT1) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // vector<int> BT2 = boundaryTraversal(root);
    // for(int i : BT2) {
    //     cout << i << " ";
    // }
    // vector<int> BT3 = verticalTraversal(root);
    // cout << endl;
    // for(int i : BT3) {
    //     cout << i << " ";
    // }
    // cout << endl;
    cout << "Top View Traversal: ";
    vector<int> BT4 = topViewTraversal(root);
    cout << endl;
    for(int i : BT4) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Bottom View Traversal: ";
    vector<int> BT5 = bottomViewTraversal(root);
    cout << endl;
    for(int i : BT5) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> BT6 = leftView(root);
    cout << endl;
    for(int i : BT6) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> BT7 = rightView(root);
    cout << endl;
    for(int i : BT7) {
        cout << i << " ";
    }
    cout << endl;
    vector<int> BT8 = diagonalTraversal(root);
    cout << endl;
    for(int i : BT8) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
