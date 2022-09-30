#pragma once
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

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

//根节点(左子树的序列化结果)(右子树的序列化结果)
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return { repeat.begin(),repeat.end() };
    }

    string dfs(TreeNode* node)
    {
        if (!node)
        {
            return "";
        }
        string serial = to_string(node->val) + "(" + dfs(node->left) + ")(" + dfs(node->right) + ")";
        if (auto it = seen.find(serial); it != seen.end())
        {
            repeat.insert(it->second);
        }
        else
        {
            seen[serial] = node;
        }
        return serial;
    }

private:
    unordered_map<string, TreeNode*> seen;
    unordered_set<TreeNode*> repeat;
};