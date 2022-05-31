#pragma once
using namespace std;
#include <string>
#include <stack>
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
 
class Solution {
public:
    //µÝ¹é
    string tree2str(TreeNode* root) {
        if (root == nullptr)
        {
            return "";
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return to_string(root->val);
        }
        if (root->right == nullptr)
        {
            return to_string(root->val) + "(" + tree2str(root->left) + ")";
        }
        return to_string(root->val) + "(" + tree2str(root->left) + ")(" + tree2str(root->right) + ")";
    }

    //µü´ú
    string tree2str(TreeNode* root) {
        string ans = "";
        stack<TreeNode*> st;
        st.push(root);
        unordered_set<TreeNode*> vis;
        while (!st.empty())
        {
            auto node = st.top();
            if (vis.count(node))
            {
                if (node != root)
                {
                    ans += ")";
                }
                st.pop();
            }
            else
            {
                vis.insert(node);
                if (node != root)
                {
                    ans += "(";
                }
                ans += to_string(node->val);
                if (node->left == nullptr && node->right != nullptr)
                {
                    ans += "()";
                }
                if (node->right != nullptr)
                {
                    st.push(node->right);
                }
                if (node->left != nullptr)
                {
                    st.push(node->left);
                }
            }
        }
        return ans;
    }
};