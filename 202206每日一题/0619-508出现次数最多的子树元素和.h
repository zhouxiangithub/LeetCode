#pragma once
using namespace std;
#include <vector>
#include <unordered_map>

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
    unordered_map<int, int> cnt; //统计每棵子树的元素和的出现次数
    int maxCnt = 0;

    int dfs(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int sum = node->val + dfs(node->left) + dfs(node->right);
        maxCnt = max(maxCnt, ++cnt[sum]);
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans;
        for (auto& [s, c] : cnt)
        {
            if (c == maxCnt)
            {
                ans.emplace_back(s);
            }
        }
        return ans;
    }
};