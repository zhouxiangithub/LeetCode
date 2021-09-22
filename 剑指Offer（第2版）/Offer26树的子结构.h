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
	bool isSubStructure(TreeNode* A, TreeNode* B)
	{
		return (A != nullptr && B != nullptr) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
	}

	bool recur(TreeNode* A, TreeNode* B)
	{
		if (B == nullptr)
		{
			return true;
		}
		if (A == nullptr || A->val != B->val)
		{
			return false;
		}
		return recur(A->left, B->left) && recur(A->right, B->right);
	}
};