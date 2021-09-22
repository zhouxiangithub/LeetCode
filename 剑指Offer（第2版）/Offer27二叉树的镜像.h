#pragma once
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
	TreeNode* mirrorTree(TreeNode* root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		TreeNode* left = mirrorTree(root->left);
		TreeNode* right = mirrorTree(root->right);
		root->left = right;
		root->right = left;
		return root;
	}
};
