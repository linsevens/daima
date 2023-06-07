#include<iostream>
#include "Tree.h"
using namespace std;

Tree::Tree()
{
	
}

TreeNode* Tree::CreateTree()
{
	int val;
	cin >> val;
	if(val==-1)
	{
		return NULL;
	}
	TreeNode* node = new TreeNode;
	node->val = val;
	node->left = CreateTree();
	node->right = CreateTree();
	return node;
}

void Tree::PreOrder(TreeNode* node)
{
	if(node==NULL)
	{
		return;
	}
	cout<<node->val<<" ";
	PreOrder(node->left);
	PreOrder(node->right);
}

void Tree::inOrder(TreeNode* node)
{
	if(node==NULL)
	{
		return;
	}
	inOrder(node->left);
	cout<<node->val<<" ";
	inOrder(node->right);
}

int Tree::GetNode(TreeNode* node)
{
	if(node==NULL)
	{
		return 0;
	}
	return GetNode(node->left)+GetNode(node->right)+1;
}

int Tree::GetLeaf(TreeNode* node)
{
	if(node==NULL)
	{
		return 0;
	}
	if(node->left==NULL&&node->right==NULL)
	{
		return 1;
	}
	return GetLeaf(node->left)+GetLeaf(node->right);
}

int Tree::GetDepth(TreeNode* node)
{
	if(node==NULL)
	{
		return 0;
	}
	int leftDepth = GetDepth(node->left);
	int rightDepth = GetDepth(node->right);
	return max(leftDepth,rightDepth)+1;
}
