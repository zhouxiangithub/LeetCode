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

class Solution {
public:
    int goodNodes(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        int goodNum = 0;
        queue<TreeNode*> node_que;
        queue<int> value_que;
        node_que.push(root);
        value_que.push(root->val);
        while (!node_que.empty())
        {
            TreeNode* node = node_que.front();
            int maxVal = value_que.front();
            node_que.pop();
            value_que.pop();
            if (node->val >= maxVal)
            {
                goodNum++;
            }
            TreeNode* left = node->left;
            if (left != nullptr)
            {
                node_que.push(left);
                value_que.push(max(maxVal, left->val));
            }
            TreeNode* right = node->right;
            if (right != nullptr)
            {
                node_que.push(right);
                value_que.push(max(maxVal, right->val));
            }
        }
        return goodNum;
    }
};