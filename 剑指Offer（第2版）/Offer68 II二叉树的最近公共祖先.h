#pragma once
using namespace std;
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
	TreeNode* ans;

	//root节点的子树中是否包含 p 节点或 q 节点
	bool dfs(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (root == nullptr)
		{
			return false;
		}
		bool lson = dfs(root->left, p, q);
		bool rson = dfs(root->right, p, q);
		if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson)))
		{
			ans = root;
		}
		return lson || rson || (root->val == p->val || root->val == q->val);
	}

	//递归
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		dfs(root, p, q);
		return ans;
	}

	/*
		利用哈希表存储所有节点的父节点，然后利用节点的父节点信息从 p 结点开始不断往上跳，
		并记录已经访问过的节点，再从 q 节点开始不断往上跳，
		如果碰到已经访问过的节点，那么这个节点就是要找的最近公共祖先。
	*/
	unordered_map<int, TreeNode*> parent;
	unordered_map<int, bool> vis;

	void dfs(TreeNode* root)
	{
		if (root->left != nullptr)
		{
			parent[root->left->val] = root;
			dfs(root->left);
		}
		if (root->right != nullptr)
		{
			parent[root->right->val] = root;
			dfs(root->right);
		}
	}

	//存储父节点
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		parent[root->val] = nullptr;
		dfs(root);
		while (p != nullptr)
		{
			vis[p->val] = true;
			p = parent[p->val];
		}
		while (q != nullptr)
		{
			if (vis[q->val])
			{
				return q;
			}
			q = parent[q->val];
		}
		return nullptr;
	}
};