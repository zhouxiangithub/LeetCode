#pragma once
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int getSubtreeSize(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        return 1 + getSubtreeSize(node->left) + getSubtreeSize(node->right);
    }

    TreeNode* find(TreeNode* node, int x)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        if (node->val == x)
        {
            return node;
        }
        TreeNode* res = find(node->left, x);
        if (res != nullptr)
        {
            return res;
        }
        else
        {
            return find(node->right, x);
        }
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int num = (n + 1) / 2;
        TreeNode* xNode = find(root, x);
        int leftSize = getSubtreeSize(xNode->left);
        if (leftSize >= num)
        {
            return true;
        }
        int rightSize = getSubtreeSize(xNode->right);
        if (rightSize >= num)
        {
            return true;
        }
        int remain = n - 1 - leftSize - rightSize;
        return remain >= num;
    }
};