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

//�����������
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long res = 1;
        //��¼ÿһ��Ŀ��
        vector<pair<TreeNode*, unsigned long long>> arr;
        arr.emplace_back(root, 1L);
        while (!arr.empty())
        {
            vector<pair<TreeNode*, unsigned long long>> tmp;
            //һ�����Ϊindex�����ӽڵ���Ϊ2*index�����ӽڵ���Ϊ2*index+1
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

//�����������
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
                //ÿһ�����ȷ��ʵ��Ľڵ��������ߵĽڵ㣬��ÿһ���ŵ���Сֵ
                levelMin[depth] = index;
            }
            return max({ index - levelMin[depth] + 1LL,dfs(node->left,depth + 1,index * 2),dfs(node->right,depth + 1,index * 2 + 1) });
        };
        return dfs(root, 1, 1LL);
    }
};