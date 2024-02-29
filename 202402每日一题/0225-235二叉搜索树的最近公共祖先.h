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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<TreeNode*> getPath(TreeNode* root, TreeNode* target)
    {
        vector<TreeNode*> path;
        TreeNode* node = root;
        while (node != target)
        {
            path.push_back(node);
            if (node->val > target->val)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }
        path.push_back(node);
        return path;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p = getPath(root, p);
        vector<TreeNode*> path_q = getPath(root, q);
        TreeNode* ancestor;
        for (int i = 0; i < path_p.size() && i < path_q.size(); i++)
        {
            if (path_p[i] == path_q[i])
            {
                ancestor = path_p[i];
            }
            else
            {
                break;
            }
        }
        return ancestor;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while (true)
        {
            if (ancestor->val > p->val && ancestor->val > q->val)
            {
                ancestor = ancestor->left;
            }
            else if (ancestor->val < p->val && ancestor->val < q->val)
            {
                ancestor = ancestor->right;
            }
            else
            {
                break;
            }
        }
        return ancestor;
    }
};