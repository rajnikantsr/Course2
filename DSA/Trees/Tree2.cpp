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
int height(node* root) {
    if(root == NULL) {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    int ans = max(left, right) + 1;
}
int diameter(node* root) {
    if(root == NULL) {
        return 0;
    }
    int opt1 = diameter(root->left);
    int opt2 = diameter(root->right);
    int opt3 = height(root->left) + height(root->right) + 1;
    int ans = max(opt1, max(opt2, opt3));
    return ans;
}
pair<int, int> diameterFast(node* root) {
    if(root == NULL) {
        pair<int, int> p = make_pair(0, 0);//Make pair makes pair of first element and second element
        return p;
    }
    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);
    int opt1 = left.first;//First implies diameter
    int opt2 = right.first;
    int opt3 = left.second + right.second + 1;//Second implies height
    pair<int, int> ans;
    ans.first = max(opt1, max(opt2, opt3));
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
bool isBalanced(node* root) {
    if(root == NULL) return true;
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    if(left && right && diff) {
        return true;
    } else {
        return false;
    }
}
pair<bool, int> IsBalanced(node* root) {
    if(root == NULL) {
        pair<bool, int> p = make_pair(1, 0);
        return p;
    }
    pair<bool, int> left = IsBalanced(root->left);
    pair<bool, int> right = IsBalanced(root->right);
    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs((left.second) - right.second) <= 1;
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;
    if(leftAns && rightAns && diff) {
        ans.first = true;
    } else {
        ans.first = false;
    }
    return ans;
}
bool isIdentical(node* r1, node* r2) {
    if(r1 == NULL && r2 == NULL) return true;
    if((r1 != NULL && r2 == NULL) && (r1 == NULL && r2 != NULL)) return false;
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    bool currValue = r1->data == r2->data;
    if(left && right && currValue) {
        return true;
    } else {
        return false;
    }
}
pair<bool, int> checkSumTree(node* root) {
    if(root == NULL) {//Base case
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
//Leaf node
    if(root->left == NULL && root->right == NULL) {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
    pair<bool, int> leftAns = checkSumTree(root->left);
    pair<bool, int> rightAns = checkSumTree(root->right);
    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;
    bool condn = root->data == leftAns.second + rightAns.second;
    pair<bool, int> ans;
    if(isLeftSumTree && isRightSumTree && condn) {
        ans.first = true;
        ans.second = 2*root->data;//or root->data + leftAns.second + rightAns.second
    } else {
        ans.first = false;
    }
    return ans;
}
int main() {
    node* root = NULL; 
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // cout << height(root);
    // cout << endl;
    // cout << diameter(root);
    // cout << endl;
    // cout << diameterFast(root).first << endl;
    // bool balanced = isBalanced(root);
    // cout << balanced;
    cout << endl;
    // pair<bool, int> Balanced = IsBalanced(root);
    // cout << Balanced.first << endl;
    node* r1 = NULL; 
    // r1 = buildTree(r1);
    // node* r2 = NULL; 
    // r2 = buildTree(r2);
    // bool identical = isIdentical(r1, r2);
    // cout << "Identical or not : " << identical << endl;
    pair<bool, int> sumTree = checkSumTree(root);
    cout << sumTree.first << endl;
    return 0;
}