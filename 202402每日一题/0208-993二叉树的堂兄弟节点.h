#pragma once
using namespace std;
#include <tuple>

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
    int x;
    TreeNode* x_parent;
    int x_depth;
    bool x_found = false;

    int y;
    TreeNode* y_parent;
    int y_depth;
    bool y_found = false;

public:
    void dfs(TreeNode* node, int depth, TreeNode* parent)
    {
        if (!node)
        {
            return;
        }

        if (node->val == x)
        {
            tie(x_parent, x_depth, x_found) = tuple{ parent,depth,true };
        }
        else if (node->val == y)
        {
            tie(y_parent, y_depth, y_found) = tuple{ parent,depth,true };
        }

        if (x_found && y_found)
        {
            return;
        }

        dfs(node->left, depth + 1, node);

        if (x_found && y_found)
        {
            return;
        }

        dfs(node->right, depth + 1, node);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        this->x = x;
        this->y = y;
        dfs(root, 0, nullptr);
        return x_depth == y_depth && x_parent != y_parent;
    }
};