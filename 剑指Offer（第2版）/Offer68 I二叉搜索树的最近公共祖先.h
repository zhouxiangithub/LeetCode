#pragma once
using namespace std;
#include <vector>

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
	//�������������Կ��ٵ��ҳ����е�ĳ���ڵ㣬�Լ��Ӹ��ڵ㵽�ýڵ��·��
	vector<TreeNode*> getPath(TreeNode* root, TreeNode* target)
	{
		vector<TreeNode*> path;
		TreeNode* node = root;
		while (node != target)
		{
			path.emplace_back(node);
			if (target->val < node->val)
			{
				node = node->left;
			}
			else
			{
				node = node->right;
			}
		}
		path.emplace_back(node);
		return path;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		vector<TreeNode*> pathP = getPath(root, p);
		vector<TreeNode*> pathQ = getPath(root, q);
		TreeNode* ans = root;
		for (int i = 0; i < pathP.size() && i < pathQ.size(); i++)
		{
			if (pathP[i] == pathQ[i])
			{
				ans = pathP[i];
			}
		}
		return ans;
	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		TreeNode* ans = root;
		while (true)
		{
			if (p->val < ans->val && q->val < ans->val)
			{
				ans = ans->left;
			}
			else if (p->val > ans->val && q->val > ans->val)
			{
				ans = ans->right;
			}
			else
			{
				break;
			}
		}
		return ans;
	}
};