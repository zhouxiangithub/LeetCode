#pragma once
using namespace std;
#include <algorithm>
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
	int maxDepth(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}

	//≥¨ ±¡À
	int maxDepth(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int ans = 0;
		vector<TreeNode*> queue, tmp;
		queue.emplace_back(root);
		while (!queue.empty())
		{
			for (TreeNode* node : queue)
			{
				if (node->left != nullptr)
				{
					tmp.emplace_back(node->left);
				}
				if (node->right != nullptr)
				{
					tmp.emplace_back(node->right);
				}
			}
			queue = tmp;
			ans++;
		}
		return ans;
	}

	int maxDepth(TreeNode* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		queue<TreeNode*> q;
		q.push(root);
		int ans = 0;
		while (!q.empty())
		{
			int size = q.size();
			while (size > 0)
			{
				TreeNode* node = q.front();
				q.pop();
				if (node->left)
				{
					q.push(node->left);
				}
				if (node->right)
				{
					q.push(node->right);
				}
				size -= 1;
			}
			ans += 1;
		}
		return ans;
	}
};