#include <iostream>
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
// Insert into BST
Node* insertNode(Node* root, int val) {
    if (root == nullptr) return new Node(val);

    if (val < root->data)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);

    return root;
}
//  (a) SEARCH IN BST
// Recursive Search
Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}
// Iterative Search
Node* searchIterative(Node* root, int key) {
    while (root != nullptr && root->data != key) {
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}
//  (b) MAXIMUM ELEMENT IN BST
Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}
//  (c) MINIMUM ELEMENT IN BST
Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}
//  (d) INORDER SUCCESSOR IN BST Next larger element
Node* inorderSuccessor(Node* root, Node* target) {
    if (target == nullptr) return nullptr;

    // Case 1: Right subtree exists → successor = minimum in right subtree
    if (target->right != nullptr)
        return findMin(target->right);

    // Case 2: No right subtree → go up to ancestor
    Node* succ = nullptr;
    while (root != nullptr) {
        if (target->data < root->data) {
            succ = root;
            root = root->left;
        } else if (target->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return succ;
}
//  (e) INORDER PREDECESSOR IN BST Next smaller element
Node* inorderPredecessor(Node* root, Node* target) {
    if (target == nullptr) return nullptr;

    // Case 1: Left subtree exists → predecessor = max in left subtree
    if (target->left != nullptr)
        return findMax(target->left);

    // Case 2: No left subtree → go up to ancestor
    Node* pred = nullptr;
    while (root != nullptr) {
        if (target->data > root->data) {
            pred = root;
            root = root->right;
        } else if (target->data < root->data) {
            root = root->left;
        } else {
            break;
        }
    }
    return pred;
}
int main() {
    Node* root = nullptr;

    int arr[] = {20, 10, 30, 5, 15, 25, 35};
    for (int x : arr) root = insertNode(root, x);

    int key = 15;
    Node* node = searchRecursive(root, key);

    if (node)
        cout << "Found: " << node->data << "\n";
    else
        cout << "Not Found\n";

    cout << "Min = " << findMin(root)->data << "\n";
    cout << "Max = " << findMax(root)->data << "\n";

    Node* succ = inorderSuccessor(root, node);
    if (succ)
        cout << "Successor of " << key << " = " << succ->data << "\n";
    else
        cout << "No Successor\n";

    Node* pred = inorderPredecessor(root, node);
    if (pred)
        cout << "Predecessor of " << key << " = " << pred->data << "\n";
    else
        cout << "No Predecessor\n";

    return 0;
}
