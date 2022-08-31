#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <functional>
#define ULL unsigned long long

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

//广度优先搜索
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long res = 1;
        //记录每一层的宽度
        vector<pair<TreeNode*, unsigned long long>> arr;
        arr.emplace_back(root, 1L);
        while (!arr.empty())
        {
            vector<pair<TreeNode*, unsigned long long>> tmp;
            //一个编号为index的左子节点编号为2*index，右子节点编号为2*index+1
            for (auto& [node, index] : arr)
            {
                if (node->left)
                {
                    tmp.emplace_back(node->left, index * 2);
                }
                if (node->right)
                {
                    tmp.emplace_back(node->right, index * 2 + 1);
                }
            }
            res = max(res, arr.back().second - arr[0].second + 1);
            arr = move(tmp);
        }
        return res;
    }
};

//深度优先搜索
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unordered_map<int, ULL> levelMin;
        function<ULL(TreeNode*, int, ULL)> dfs = [&](TreeNode* node, int depth, ULL index)->ULL {
            if (node == nullptr)
            {
                return 0LL;
            }
            if (!levelMin.count(depth))
            {
                //每一层最先访问到的节点会是最左边的节点，即每一层编号的最小值
                levelMin[depth] = index;
            }
            return max({ index - levelMin[depth] + 1LL,dfs(node->left,depth + 1,index * 2),dfs(node->right,depth + 1,index * 2 + 1) });
        };
        return dfs(root, 1, 1LL);
    }
};