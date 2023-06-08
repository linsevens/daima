#include <iostream>
#include <algorithm>
using namespace std; 
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    int height;

    TreeNode(int val) : data(val), left(NULL), right(NULL), height(1) {}
};

int height(TreeNode* node) {
    return node ? node->height : 0;
}

int balanceFactor(TreeNode* node) {
    return height(node->left) - height(node->right);
}

TreeNode* leftRotate(TreeNode* root) {
    TreeNode* newRoot = root->right;
    TreeNode* leftOfNewRoot = newRoot->left;

    newRoot->left = root;
    root->right = leftOfNewRoot;

    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

TreeNode* rightRotate(TreeNode* root) {
    TreeNode* newRoot = root->left;
    TreeNode* rightOfNewRoot = newRoot->right;

    newRoot->right = root;
    root->left = rightOfNewRoot;

    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

TreeNode* insert(TreeNode* root, int data) {
    if (!root) return new TreeNode(data);

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    } else {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = balanceFactor(root);

    if (balance > 1 && data < root->left->data) {
        return rightRotate(root);
    }
    
    if (balance < -1 && data > root->right->data) {
        return leftRotate(root);
    }

    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);
    root = insert(root, 70);

    cout << "构建的AVL树中序遍历结果为:" << endl;
    inorder(root);
    cout << endl;

    return 0;
}

