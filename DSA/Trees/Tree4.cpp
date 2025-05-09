#include <iostream>
#include <vector>
#include<climits>
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
void solve(node* root, int sum, int &maxSum, int len, int&maxLen) {
    if(root == NULL) {
        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen) {
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum = sum+root->data;
    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);
}
int sumOfLongLeafPath(node* root) {
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = 0;
    solve(root, sum, maxSum, len, maxLen);
    return maxSum;
}
node* lca(node* root, int n1, int n2) {
    if(root == NULL) return NULL;
    if(root->data == n1 || root->data == n2) {
        return root;
    }
    node* leftAns = lca(root->left, n1, n2);
    node* rightAns = lca(root->right, n1, n2);
    if(leftAns != NULL && rightAns != NULL) {
        return root;
    }
    else if(leftAns == NULL && rightAns != NULL) {
        return rightAns;
    }
    else if(leftAns != NULL && rightAns == NULL) {
        return leftAns;
    }
    else {
        return NULL;
    }
}
void solve2(node* root, int k, int&count, vector<int> path) {
    if(root == NULL) return;
    path.push_back(root->data);
    solve2(root->left, k, count, path);
    solve2(root->right, k, count, path);
    int size = path.size();
    int sum = 0;
    for(int i = size-1; i>=0; i--) {
        sum += path[i];
        if(sum == k)
            count++;
    }
    path.pop_back();
}
int sumK(node* root, int k) {
    vector<int> path;
    int count = 0;
    solve2(root, k, count, path);
    return count;
}

bool solve3(node* root, int target, vector<int>& path) {
    if (root == NULL) return false;
    path.push_back(root->data);
    if (root->data == target) return true;
    // Check left and right
    if (solve3(root->left, target, path) || solve3(root->right, target, path))
        return true;
    // Backtrack
    path.pop_back();
    return false;
}

int kthAncestor(node* root, int k, int target) {
    vector<int> path; 
    if (!solve3(root, target, path)) {
        cout << "Target node not found.\n";
        return -1;
    }
    int size = path.size();
    if (size <= k) {
        cout << "No such ancestor exists.\n";
        return -1;
    }
    return path[size - k - 1]; // kth ancestor from end
}
node* Solve3(node* root, int& k, int target) {
    if (root == NULL) return NULL;
    if (root->data == target) return root;
    node* left = Solve3(root->left, k, target);
    node* right = Solve3(root->right, k, target);
    if (left || right) {
        k--;
        if (k == 0) {
            k = INT_MAX;
        }
        return root;
    }
    return NULL;
}

int KthAncestor(node* root, int k, int target) {
    node* ans = Solve3(root, k, target);
    if(ans == NULL || ans->data == target) {
        return -1;
    } else{
        return ans->data;
    }
}
pair<int, int> solve4(node* root){
    if(root == NULL) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = solve4(root->left);
    pair<int, int> right = solve4(root->right);
    pair<int, int> res;
    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);
    return res;
} 
int getMaxSum(node* root) {
    pair<int, int> ans = solve4(root);
    return max(ans.first, ans.second);
}
int main() {
    node* root = NULL;
    root = buildTree(root);
    // cout << sumOfLongLeafPath(root) << endl;
    // int n1, n2;
    // cin >> n1 >> n2;
    // cout << "LCA of n1 and n2" << lca(root, n1, n2)->data << endl;
    // int k = 2;
    // int target;
    // cout << "Enter target element from binary tree -> " << endl;
    // cin >> target;
    // // cout << "path having sum as k" << sumK(root, k) << endl;
    // // cout << kthAncestor(root, k, target);
    // cout << KthAncestor(root, k, target);
    cout << getMaxSum(root) << endl;
    return 0;
}