#pragma once
using namespace std;
#include <unordered_set>
#include <queue>
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
public:
    //深度优先搜索+哈希表
    unordered_set<int> hashTable;

    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr)
        {
            return false;
        }
        if (hashTable.count(k - root->val))
        {
            return true;
        }
        hashTable.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }

    //广度优先搜索+哈希表
    bool findTarget1(TreeNode* root, int k) {
        unordered_set<int> hashTable; //记录遍历过的节点的值
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode* node = que.front();
            que.pop();
            if (hashTable.count(k - node->val))
            {
                return true;
            }
            hashTable.insert(node->val);
            if (node->left != nullptr)
            {
                que.push(node->left);
            }
            if (node->right != nullptr)
            {
                que.push(node->right);
            }
        }
        return false;
    }

    //深度优先搜索+中序遍历+双指针
    vector<int> vec;

    void inorderTraversal(TreeNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        inorderTraversal(node->left);
        vec.push_back(node->val);
        inorderTraversal(node->right);
    }

    bool findTarget2(TreeNode* root, int k) {
        inorderTraversal(root);
        int left = 0, right = vec.size() - 1;
        while (left < right)
        {
            if (vec[left] + vec[right] == k)
            {
                return true;
            }
            if (vec[left] + vec[right] < k)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return false;
    }
};