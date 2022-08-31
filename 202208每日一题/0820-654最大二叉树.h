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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//ตÝน้
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }

    TreeNode* construct(const vector<int>& nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int max = left;
        for (int i = left + 1; i <= right; i++)
        {
            if (nums[i] > nums[max])
            {
                max = i;
            }
        }
        TreeNode* node = new TreeNode(nums[max]);
        node->left = construct(nums, left, max - 1);
        node->right = construct(nums, max + 1, right);
        return node;
    }
};