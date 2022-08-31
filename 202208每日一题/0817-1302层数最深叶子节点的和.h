#pragma once
using namespace std;
#include <queue>

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

//�����������
class Solution {
private:
    int maxLevel = -1;
    int sum = 0;

public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode* node, int level)
    {
        if (node == nullptr)
        {
            return;
        }
        if (level > maxLevel)
        {
            maxLevel = level;
            sum = node->val;
        }
        else if (level == maxLevel)
        {
            sum += node->val;
        }
        dfs(node->left, level + 1);
        dfs(node->right, level + 1);
    }
};

//�����������
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> qu;
        qu.emplace(root);
        while (!qu.empty())
        {
            sum = 0;
            int size = qu.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = qu.front();
                qu.pop();
                sum += node->val;
                if (node->left != nullptr)
                {
                    qu.emplace(node->left);
                }
                if (node->right != nullptr)
                {
                    qu.emplace(node->right);
                }
            }
        }
        return sum;
    }
};