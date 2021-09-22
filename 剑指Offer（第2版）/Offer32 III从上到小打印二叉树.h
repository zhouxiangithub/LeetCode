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
	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> res;
		if (root == nullptr)
		{
			return res;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (q.size())
		{
			vector<int> tmp;
			int qSize = q.size();
			for (int i = 0; i < qSize; i++)
			{
				TreeNode* node = q.front();
				q.pop();
				tmp.push_back(node->val);
				if (node->left)
				{
					q.push(node->left);
				}
				if (node->right)
				{
					q.push(node->right);
				}
			}
			res.push_back(tmp);
		}
		for (int i = 1; i < res.size(); i += 2)
		{
			reverse(res[i].begin(), res[i].end());
		}
		return res;
	}
};