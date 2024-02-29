#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <functional>

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
    unordered_map<int, int> index;

public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& postorder, int pre_left, int pre_right, int post_left, int post_right)
    {
        if (pre_left > pre_right)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pre_left]);

        int size_left_subtree = 0;

        if (pre_left < pre_right) //考虑二叉树为单个节点的情况
        {
            size_left_subtree = index[preorder[pre_left + 1]] - post_left + 1;
        }

        root->left = myBuildTree(preorder, postorder, pre_left + 1, pre_left + size_left_subtree, post_left, post_left + size_left_subtree - 1);

        root->right = myBuildTree(preorder, postorder, pre_left + size_left_subtree + 1, pre_right, post_left + size_left_subtree, post_right - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++)
        {
            index[postorder[i]] = i;
        }
        return myBuildTree(preorder, postorder, 0, n - 1, 0, n - 1);
    }
};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++)
        {
            index[postorder[i]] = i;
        }
        function<TreeNode* (int, int, int, int)> dfs = [&](int pre_left, int pre_right, int post_left, int post_right)->TreeNode* {
            if (pre_left > pre_right)
            {
                return nullptr;
            }
            int size_left_subtree = 0;
            if (pre_left < pre_right)
            {
                size_left_subtree = index[preorder[pre_left + 1]] - post_left + 1;
            }
            return new TreeNode(preorder[pre_left],
                dfs(pre_left + 1, pre_left + size_left_subtree, post_left, post_left + size_left_subtree - 1),
                dfs(pre_left + size_left_subtree + 1, pre_right, post_left + size_left_subtree, post_right - 1));
        };
        return dfs(0, n - 1, 0, n - 1);
    }
};
