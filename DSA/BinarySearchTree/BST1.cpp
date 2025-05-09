#include<iostream>
#include<queue>
#include<climits>
using namespace std;
class node{
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
node* insertIntoBST(node* &root, int data) {
    if(root == NULL) {
        root = new node(data);
        return root;
    }
    if(data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}
void takeInput(node* &root) {
    int data;
    cin >> data;
    while(data!=-1) {
        insertIntoBST(root, data);
        cin >> data;
    }
}
void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if(temp->left) {
                q.push(temp->left);
            } 
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}
// //Recursive way TC = O(logn) SC = O(H)
// bool searchInBST(node* root, int x) {
//     if(root == NULL) return false;
//     if(root->data == x) return true;
//     if(root->data > x) {
//         return searchInBST(root->left, x);
//     } else {
//         return searchInBST(root->right, x);
//     }
// }
bool searchInBST(node* root, int x) {
    node* temp = root;
    while(temp!=NULL) {
        if(temp->data == x) return true;
        if(temp->data > x) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return false;
}
node* minValue(node* root) {
    node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}
node* maxValue(node* root) {
    node* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}
node* predecessor(node* root, int key) {
    node* pre = NULL;
    while(root != NULL) {
        if(root->data >= key) {
            root = root->left;
        } else {
            pre = root;
            root = root->right;
        }
    }
    return pre;
}
node* successor(node* root, int key) {
    node* succ = NULL;
    while(root != NULL) {
        if(root->data > key) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}
node* nodeToDelete(node* &root, int val) {
    if(root == NULL) return root;
    if(root->data == val) {
        //0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        //1 child
        if(root->left!=NULL && root->right==NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left != NULL && root->right != NULL) {
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = nodeToDelete(root->right, mini);
            return root;
        }
    }
    else if(root->data>val) {
        root->left = nodeToDelete(root->left, val);
        return root;
    } else {
        root->right = nodeToDelete(root->right, val);
        return root;
    }
}
bool isBSTValidate(node* root, int min, int max) {
    if(root == NULL) return true;
    if(root->data >= min && root->data <= max) {
        bool left = isBSTValidate(root->left, min, root->data);
        bool right = isBSTValidate(root->right, root->data, max);
        return left && right;
    } else {
        return false;
    }
}
bool validate(node* root) {
    return isBSTValidate(root, INT_MIN, INT_MAX);
}
int solveKthSmallest(node* root, int &i, int key) {
    if(root == NULL) return -1;
    int left = solveKthSmallest(root->left, i, key);
    if (left != -1) {
        return left;
    }
    i++;
    if(i == key) {
        return root->data;
    }
    return solveKthSmallest(root->right, i, key);
}
int kthSmallest(node* root, int k) {
    int i = 0;
    int ans = solveKthSmallest(root, i, k);
    return ans;
}
int main() {
    node* root = NULL;
    cout << "Enter data to Create BST " << endl;
    takeInput(root);
    levelOrderTraversal(root);
    // int x = 6;
    // cout << searchInBST(root, x);
    // //Min/Max
    // cout << "Min Value: " << minValue(root)->data << endl;
    // cout << "Max Value: " << maxValue(root)->data << endl; 
    // //Predessor / Successor
    // int key;
    // cin >> key;
    // cout << "Precessor value:" << predecessor(root, key)->data << endl;
    // cout << "Successor value:" << successor(root, key)->data << endl;
    // cout << endl << endl;
    // root = nodeToDelete(root, 50);
    // cout << endl << endl;
    // levelOrderTraversal(root);
    // cout << validate(root);
    cout << kthSmallest(root, 3);
    return 0;
}