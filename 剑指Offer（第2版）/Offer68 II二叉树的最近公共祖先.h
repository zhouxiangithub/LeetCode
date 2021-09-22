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

	//root�ڵ���������Ƿ���� p �ڵ�� q �ڵ�
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

	//�ݹ�
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		dfs(root, p, q);
		return ans;
	}

	/*
		���ù�ϣ��洢���нڵ�ĸ��ڵ㣬Ȼ�����ýڵ�ĸ��ڵ���Ϣ�� p ��㿪ʼ������������
		����¼�Ѿ����ʹ��Ľڵ㣬�ٴ� q �ڵ㿪ʼ������������
		��������Ѿ����ʹ��Ľڵ㣬��ô����ڵ����Ҫ�ҵ�����������ȡ�
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

	//�洢���ڵ�
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