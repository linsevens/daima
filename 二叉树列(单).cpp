#include <iostream>
#include <queue>

using namespace std;

// 定义二叉树结点类
class TreeNode {
public:
    int val; // 值
    TreeNode* left; // 左节点
    TreeNode* right; // 右节点

    // 构造函数
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// 定义二叉树类
class BinaryTree {
public:
    TreeNode* root; // 根节点

    // 构造函数
    BinaryTree() {
        root = NULL;
    }

//    // 析构函数
//    ~BinaryTree() {
//        freeTree(root);
//    }

    // 创建二叉树
    TreeNode* createTree() {
        int val;
        cin >> val;
        if (val == -1) {
            return NULL;
        }
        TreeNode* node = new TreeNode(val);
        node->left = createTree();
        node->right = createTree();
        return node;
    }

    // 前序遍历
    void preOrder(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        cout << node->val << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // 中序遍历
    void inOrder(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    }

    // 后序遍历
    void postOrder(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        cout << node->val << " ";
    }

    // 求二叉树结点数
    int getNodeCount(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        return getNodeCount(node->left) + getNodeCount(node->right) + 1;
    }

    // 求二叉树叶子数
    int getLeafCount(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        if (node->left == NULL && node->right == NULL) {
            return 1;
        }
        return getLeafCount(node->left) + getLeafCount(node->right);
    }

    // 求二叉树深度
    int getDepth(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        return max(leftDepth, rightDepth) + 1;
    }

    // 层序遍历
    void levelOrder() {
        if (root == NULL) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }
};

int main() {
    // 创建二叉树
    BinaryTree tree;
    tree.root = tree.createTree();

    // 遍历
    cout << "前序遍历：";
    tree.preOrder(tree.root);
    cout << endl;

    cout << "中序遍历：";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "后序遍历：";
    tree.postOrder(tree.root);
    cout << endl;

    cout << "层序遍历：";
    tree.levelOrder();
    cout << endl;

    // 结点数、叶子数、深度
    cout << "结点数：" << tree.getNodeCount(tree.root) << endl;
    cout << "叶子数：" << tree.getLeafCount(tree.root) << endl;
    cout << "深度：" << tree.getDepth(tree.root) << endl;

    // 二叉树转换为二叉平衡树

    return 0;
}
