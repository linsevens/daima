#include<iostream>
#include "Tree.h"
using namespace std;

int main()
{
	Tree tree;
	TreeNode* root=tree.CreateTree();
	tree.PreOrder(root);
	cout<<endl;
	tree.inOrder(root);
	cout<<endl;
	cout<<"节点数为:"<<tree.GetNode(root)<<endl;
	cout<<"叶子数为:"<<tree.GetLeaf(root)<<endl;
	cout<<"深度为:"<<tree.GetDepth(root)<<endl;
	return 0;	
} 
