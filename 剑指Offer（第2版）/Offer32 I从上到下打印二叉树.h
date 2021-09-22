#pragma once
using namespace std;
#include <vector>
#include <queue>

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
	vector<int> levelOrder(TreeNode* root)
	{
		vector<int> res;
		if (root == nullptr)
		{
			return res;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (q.size())
		{
			TreeNode* node = q.front();
			q.pop();
			res.push_back(node->val);
			if (node->left)
			{
				q.push(node->left);
			}
			if (node->right)
			{
				q.push(node->right);
			}
		}
		return res;
	}
};
