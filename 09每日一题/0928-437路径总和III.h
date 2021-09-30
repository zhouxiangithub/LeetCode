#pragma once
using namespace std;
#include <unordered_map>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};

class Solution
{
public:
	//�����������
	int rootSum(TreeNode* root, int targetSum)
	{
		if (!root)
		{
			return 0;
		}
		int ret = 0;
		if (root->val == targetSum)
		{
			ret++;
		}
		ret += rootSum(root->left, targetSum - root->val);
		ret += rootSum(root->right, targetSum - root->val);
		return ret;
	}
	
	int pathSum(TreeNode* root, int targetSum)
	{
		if (!root)
		{
			return 0;
		}
		int ret = rootSum(root, targetSum);
		ret += pathSum(root->left, targetSum);
		ret += pathSum(root->right, targetSum);
		return ret;
	}

	//ǰ׺��
	unordered_map<long long, int> prefix; //<ֵ����Ŀ>
	
	int dfs(TreeNode* root, long long curr, int targetSum)
	{
		if (!root)
		{
			return 0;
		}
		int ret = 0;
		curr += root->val;
		if (prefix.count(curr - targetSum))
		{
			ret = prefix[curr - targetSum];
		}
		prefix[curr]++;
		ret += dfs(root->left, curr, targetSum);
		ret += dfs(root->right, curr, targetSum);
		prefix[curr]--;
		return ret;
	}

	int pathSum(TreeNode* root, int targetSum)
	{
		prefix[0] = 1;
		return dfs(root, 0, targetSum);
	}
};