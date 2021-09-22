#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
	/*
		递归：
			前序遍历：根，左子树前序遍历，右子树前序遍历
							/               /
			中序遍历：左子树中序遍历，根，右子树中序遍历
		关键点：
			定位中序遍历的根节点
	*/
	unordered_map<int, int> index; //(节点值，索引)

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		int n = preorder.size();
		for (int i = 0; i < n; i++)
		{
			index[inorder[i]] = i; //构造中序遍历的哈希映射
		}
		return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
	}

	TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR)
	{
		if (preL > preR)
		{
			return nullptr;
		}
		int preRoot = preL; //前序遍历的第一个节点就是根节点
		int inRoot = index[preorder[preL]]; //定位中序遍历的根节点
		int subtreeL = inRoot - inL; //左子树的数目

		TreeNode* root = new TreeNode(preorder[preRoot]);
		root->left = myBuildTree(preorder, inorder, preL + 1, preL + subtreeL, inL, inRoot - 1);
		root->right = myBuildTree(preorder, inorder, preL + subtreeL + 1, preR, inRoot + 1, inR);
		return root;
	}
};