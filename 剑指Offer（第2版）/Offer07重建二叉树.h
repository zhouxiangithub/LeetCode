#pragma once
using namespace std;
#include <vector>
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
	/*
		�ݹ飺
			ǰ�����������������ǰ�������������ǰ�����
							/               /
			�����������������������������������������
		�ؼ��㣺
			��λ��������ĸ��ڵ�
	*/
	unordered_map<int, int> index; //(�ڵ�ֵ������)

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		int n = preorder.size();
		for (int i = 0; i < n; i++)
		{
			index[inorder[i]] = i; //������������Ĺ�ϣӳ��
		}
		return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
	}

	TreeNode* myBuildTree(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR)
	{
		if (preL > preR)
		{
			return nullptr;
		}
		int preRoot = preL; //ǰ������ĵ�һ���ڵ���Ǹ��ڵ�
		int inRoot = index[preorder[preL]]; //��λ��������ĸ��ڵ�
		int subtreeL = inRoot - inL; //����������Ŀ

		TreeNode* root = new TreeNode(preorder[preRoot]);
		root->left = myBuildTree(preorder, inorder, preL + 1, preL + subtreeL, inL, inRoot - 1);
		root->right = myBuildTree(preorder, inorder, preL + subtreeL + 1, preR, inRoot + 1, inR);
		return root;
	}
};