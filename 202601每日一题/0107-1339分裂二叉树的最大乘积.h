#pragma once
using namespace std;
#include <algorithm>

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
    static constexpr int mod = 1e9 + 7;
    int sum = 0;
    int mid = 0;

private:
    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        sum += node->val;
        dfs(node->left);
        dfs(node->right);
    }

    int dfs2(TreeNode* node) {
        if (!node) {
            return 0;
        }
        int curVal = dfs2(node->left) + dfs2(node->right) + node->val;
        if (abs(curVal * 2 - sum) < abs(mid * 2 - sum)) {
            mid = curVal;
        }
        return curVal;
    }

public:
    int maxProduct(TreeNode* root) {
        dfs(root);
        dfs2(root);
        return (long long)mid * (sum - mid) % mod;
    }
};