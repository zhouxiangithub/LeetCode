#pragma once
using namespace std;
#include <algorithm>

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
	int height(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		else
		{
			return max(height(root->left), height(root->right)) + 1;
		}
	}

	bool isBalanced(TreeNode* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		else
		{
			return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
		}
	}

	int height_(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int leftHeight = height_(root->left);
		int rightHeight = height_(root->right);
		if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
		{
			return -1;
		}
		else
		{
			return max(leftHeight, rightHeight) + 1;
		}
	}

	bool isBalanced(TreeNode* root)
	{
		return height_(root) >= 0;
	}
};