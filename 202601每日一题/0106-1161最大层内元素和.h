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

class Solution {
private:
    vector<int> sum;

    void dfs(TreeNode* node, int level) {
        if (level == sum.size()) {
            sum.push_back(node->val);
        }
        else {
            sum[level] += node->val;
        }

        if (node->left) {
            dfs(node->left, level + 1);
        }
        if (node->right) {
            dfs(node->right, level + 1);
        }
    }

public:
    int maxLevelSum(TreeNode* root) {
        dfs(root, 0);
        int res = 0;
        for (int i = 0; i < sum.size(); i++) {
            if (sum[i] > sum[res]) {
                res = i;
            }
        }
        return res + 1;
    }
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int res = 1, maxSum = root->val;
        vector<TreeNode*> q = { root };
        for (int level = 1; !q.empty(); level++) {
            vector<TreeNode*> nq;
            int sum = 0;
            for (auto node : q) {
                sum += node->val;
                if (node->left) {
                    nq.emplace_back(node->left);
                }
                if (node->right) {
                    nq.emplace_back(node->right);
                }
            }
            if (sum > maxSum) {
                maxSum = sum;
                res = level;
            }
            q = move(nq);
        }
        return res;
    }
};