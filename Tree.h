#ifndef Tree_H
#define Tree_H
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Tree
{
	public:
		Tree();
		TreeNode* CreateTree();
		void PreOrder(TreeNode* node);
		void inOrder(TreeNode* node);
		void postOrder(TreeNode* node);
		int GetNode(TreeNode* node);
		int GetLeaf(TreeNode* node);
		int GetDepth(TreeNode* node);
		
};
#endif;
