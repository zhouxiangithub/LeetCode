#pragma once
using namespace std;

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

/*
    遍历右子节点
    当遍历的节点的值大于val时，由于val是新添加的位于数组末尾的元素，那么在构造的结果中，val一定出现在该节点的右子树中。
*/
class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        TreeNode* parent = nullptr;
        TreeNode* cur = root;
        while (cur)
        {
            if (val > cur->val)
            {
                if (!parent)
                {
                    return new TreeNode(val, cur, nullptr);
                }
                TreeNode* node = new TreeNode(val, cur, nullptr);
                parent->right = node;
                return root;
            }
            else
            {
                parent = cur;
                cur = cur->right;
            }
        }
        parent->right = new TreeNode(val);
        return root;
    }
};

class Solution {
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root || root->val < val)
        {
            return new TreeNode(val, root, nullptr);
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};