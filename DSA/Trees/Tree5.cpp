#include<iostream>
#include<map>
#include<queue>
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
// Map inorder values to index for fast lookup
void findPosWithMapping(int in[], map<int, int>& nodeToIndex, int n) {
    for (int i = 0; i < n; i++) {
        nodeToIndex[in[i]] = i;
    }
}

// Build tree from preorder and inorder
node* solve1(int in[], int pre[], int& index, int inOrderStart, int inOrderEnd, int n, map<int, int>& nodeToIndex) {
    if (index >= n || inOrderStart > inOrderEnd) {
        return NULL;
    }

    int element = pre[index++];
    node* root = new node(element);

    int pos = nodeToIndex[element];

    root->left = solve1(in, pre, index, inOrderStart, pos - 1, n, nodeToIndex);
    root->right = solve1(in, pre, index, pos + 1, inOrderEnd, n, nodeToIndex);

    return root;
}

node* buildTree1(int in[], int pre[], int n) {
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;
    findPosWithMapping(in, nodeToIndex, n);
    return solve1(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
}

// Build tree from postorder and inorder
node* solve2(int in[], int post[], int& index, int inOrderStart, int inOrderEnd, int n, map<int, int>& nodeToIndex) {
    if (index < 0 || inOrderStart > inOrderEnd) {
        return NULL;
    }

    int element = post[index--];
    node* root = new node(element);

    int pos = nodeToIndex[element];

    root->right = solve2(in, post, index, pos + 1, inOrderEnd, n, nodeToIndex);
    root->left = solve2(in, post, index, inOrderStart, pos - 1, n, nodeToIndex);

    return root;
}

node* buildTree2(int in[], int post[], int n) {
    int postOrderIndex = n - 1;
    map<int, int> nodeToIndex;
    findPosWithMapping(in, nodeToIndex, n);
    return solve2(in, post, postOrderIndex, 0, n - 1, n, nodeToIndex);
}

// Traversal to verify correctness
void postorder(node* root) {
    if (root == NULL) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
//It will create mapping as well as finding target
node* createParentMapping(node* root, int target, map<node*, node*>& nodeToParent) {
    node* res = NULL;//For returning of target
    queue<node*> q;
    q.push(root);
    nodeToParent[root] = NULL;
    while(!q.empty()) {
        node* front = q.front();
        q.pop();
        if(front -> data == target) {
            res = front;
        }
        if(front->left) {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right) {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}
int burnTree(node* root, map<node*, node*>& nodeToParent) {
    map<node*, bool> visited;
    queue<node*> q;
    q.push(root);
    visited[root]=true;
    int ans = 0;
    while(!q.empty()) {
        bool flag = 0;
        int size = q.size();
        for(int i = 0; i<size; i++) {
            //Process neighbouring nodes
            node* front = q.front();
            q.pop();
            if(front->left && !visited[front->left]) {
                q.push(front->left);
                visited[front->left] = 1;
                flag = 1;
            }
            if(front->right && !visited[front->right]) {
                q.push(front->right);
                visited[front->right] = 1;
                flag = 1;
            }
            if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
                flag = 1;
            }
            if(flag == 1) {
                ans++;
            }
        }
        
    }
    return ans;
}
int minTime(node* root, int target) {
    int ans = 0;
    map<node*, node*> nodeToParent;
    node* targetNode = createParentMapping(root, target, nodeToParent);
    return burnTree(targetNode, nodeToParent);
}
vector<int> morrisTraversal(node* root) {
    vector<int> res;
    node* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            // If no left child, visit this node 
            // and go right
            res.push_back(curr->data);
            curr = curr->right;
        }
        else {
            // Find the inorder predecessor of curr
            node* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }
            // Make curr the right child of its 
            // inorder predecessor
            if(prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } 
            else {
                // Revert the changes made in 
                // the tree structure
                prev->right = nullptr;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return res;
}
int main() {
    node* root = NULL;
    root = buildTree(root);
    // int inorder[] = {3, 1, 4, 0, 5, 2};
    // int preorder[] = {0, 1, 3, 4, 2, 5};     // for buildTree1
    // int postOrder[] = {3, 4, 1, 5, 2, 0}; // for buildTree2

    // node* temp1 = buildTree1(inorder, preorder, 6);
    // node* temp2 = buildTree2(inorder, postOrder, 6);

    // cout << "Postorder of tree built from preorder + inorder: ";
    // postorder(temp1);  // Should match postorderArr
    // cout << endl;

    // cout << "Postorder of tree built from postorder + inorder: ";
    // postorder(temp2);  // Should match postorderArr
    cout << endl;
    int target;
    cout << "Enter target for burning tree" << endl;
    cin >> target;
    cout << minTime(root, target);
    vector<int> temp = morrisTraversal(root);
    for(int i = 0; i<temp.size(); i++) {
        cout << temp[i] << " ";
    } cout << endl;
    return 0;
}
