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
	cout<<"�ڵ���Ϊ:"<<tree.GetNode(root)<<endl;
	cout<<"Ҷ����Ϊ:"<<tree.GetLeaf(root)<<endl;
	cout<<"���Ϊ:"<<tree.GetDepth(root)<<endl;
	return 0;	
} 
