#pragma once
using namespace std;
#include <vector>

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
    vector<int> sum;

    void dfs(TreeNode* node, int level)
    {
        if (level == sum.size())
        {
            sum.push_back(node->val);
        }
        else
        {
            sum[level] += node->val;
        }
        if (node->left)
        {
            dfs(node->left, level + 1);
        }
        if (node->right)
        {
            dfs(node->right, level + 1);
        }
    }
public:
    int maxLevelSum(TreeNode* root) {
        dfs(root, 0);
        int ans = 0;
        for (int i = 0; i < sum.size(); i++)
        {
            if (sum[i] > sum[ans])
            {
                ans = i;
            }
        }
        return ans + 1;
    }
};

//�����������
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = 1, maxSum = root->val;
        vector<TreeNode*> q = { root }; //q�洢��ǰ��Ľڵ�
        for (int level = 1; !q.empty(); level++)
        {
            vector<TreeNode*> nq; //nq�洢��һ��Ľڵ�
            int sum = 0;
            for (auto node : q)
            {
                sum += node->val;
                if (node->left)
                {
                    nq.emplace_back(node->left);
                }
                if (node->right)
                {
                    nq.emplace_back(node->right);
                }
            }
            if (sum > maxSum)
            {
                maxSum = sum;
                ans = level;
            }
            q = move(nq);
        }
        return ans;
    }
};