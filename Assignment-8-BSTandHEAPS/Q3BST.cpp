#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
//  (a) INSERT 
Node* insertNode(Node* root, int val) {
    if (root == nullptr)
        return new Node(val);

    if (val < root->data)
        root->left = insertNode(root->left, val);
    else if (val > root->data)
        root->right = insertNode(root->right, val);
    else
        cout << "Duplicate not allowed: " << val << endl;

    return root;
}
//  HELPER: Find minimum in BST (used for deletion)
Node* findMin(Node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}

/* -------------------------------------------------------
   (b) DELETE NODE FROM BST
    3 Cases:
        1. Leaf node
        2. One child
        3. Two children → replace by inorder successor
--------------------------------------------------------*/
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {  
        // Node found
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* succ = findMin(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }
    return root;
}
//  (c) MAXIMUM DEPTH OF BST def: longest path root → leaf
int maxDepth(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
//  (d) MINIMUM DEPTH OF BST  def: shortest path root → leaf
int minDepth(Node* root) {
    if (root == nullptr) return 0;
    // If one child is null → depth = other child + 1
    if (root->left == nullptr)
        return 1 + minDepth(root->right);
    if (root->right == nullptr)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    Node* root = nullptr;

    int arr[] = {20, 10, 30, 5, 15, 25, 35};
    for (int x : arr)
        root = insertNode(root, x);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 10);
    cout << "After deleting 10: ";
    inorder(root);
    cout << endl;

    cout << "Maximum Depth = " << maxDepth(root) << endl;
    cout << "Minimum Depth = " << minDepth(root) << endl;

    return 0;
}
