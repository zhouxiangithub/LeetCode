#pragma once
using namespace std;
#include <vector>
#include <array>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

/*
	������
		������������   3
		             /\
					1  4
					 \
					 2
		�������Ϊ��1234
		��ˣ�����������ĵ�����k��������
*/
class Solution
{
public:
	int res = 0, count = 0;

	void dfs(TreeNode* root, int k)
	{
		if (root == nullptr)
		{
			return;
		}
		if (root->right != nullptr)
		{
			dfs(root->right, k);
		}
		if (++count == k)
		{
			res = root->val;
			return;
		}
		if (root->left != nullptr)
		{
			dfs(root->left, k);
		}
	}
	
	int kthLargest(TreeNode* root, int k)
	{
		dfs(root, k);
		return res;
	}
};