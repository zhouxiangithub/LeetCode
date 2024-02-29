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
private:
    unordered_map<int, int> index;

public:
    TreeNode* myBuildTree(const vector<int>& inorder, const vector<int>& postorder, int in_left, int in_right, int post_left, int post_right)
    {
        if (in_left > in_right)
        {
            return nullptr;
        }

        int postorder_root = post_right;

        int inorder_root = index[postorder[postorder_root]];

        TreeNode* root = new TreeNode(postorder[postorder_root]);

        int size_left_subtree = inorder_root - in_left;

        root->left = myBuildTree(inorder, postorder, in_left, inorder_root - 1, post_left, post_left + size_left_subtree - 1);

        root->right = myBuildTree(inorder, postorder, inorder_root + 1, in_right, post_left + size_left_subtree, post_right - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            index[inorder[i]] = i;
        }
        return myBuildTree(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};