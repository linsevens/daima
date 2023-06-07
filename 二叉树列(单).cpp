#include <iostream>
#include <queue>

using namespace std;

// ��������������
class TreeNode {
public:
    int val; // ֵ
    TreeNode* left; // ��ڵ�
    TreeNode* right; // �ҽڵ�

    // ���캯��
    TreeNode(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// �����������
class BinaryTree {
public:
    TreeNode* root; // ���ڵ�

    // ���캯��
    BinaryTree() {
        root = NULL;
    }

//    // ��������
//    ~BinaryTree() {
//        freeTree(root);
//    }

    // ����������
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

    // ǰ�����
    void preOrder(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        cout << node->val << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // �������
    void inOrder(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    }

    // �������
    void postOrder(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        postOrder(node->left);
        postOrder(node->right);
        cout << node->val << " ";
    }

    // ������������
    int getNodeCount(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        return getNodeCount(node->left) + getNodeCount(node->right) + 1;
    }

    // �������Ҷ����
    int getLeafCount(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        if (node->left == NULL && node->right == NULL) {
            return 1;
        }
        return getLeafCount(node->left) + getLeafCount(node->right);
    }

    // ����������
    int getDepth(TreeNode* node) {
        if (node == NULL) {
            return 0;
        }
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);
        return max(leftDepth, rightDepth) + 1;
    }

    // �������
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
    // ����������
    BinaryTree tree;
    tree.root = tree.createTree();

    // ����
    cout << "ǰ�������";
    tree.preOrder(tree.root);
    cout << endl;

    cout << "���������";
    tree.inOrder(tree.root);
    cout << endl;

    cout << "���������";
    tree.postOrder(tree.root);
    cout << endl;

    cout << "���������";
    tree.levelOrder();
    cout << endl;

    // �������Ҷ���������
    cout << "�������" << tree.getNodeCount(tree.root) << endl;
    cout << "Ҷ������" << tree.getLeafCount(tree.root) << endl;
    cout << "��ȣ�" << tree.getDepth(tree.root) << endl;

    // ������ת��Ϊ����ƽ����

    return 0;
}
