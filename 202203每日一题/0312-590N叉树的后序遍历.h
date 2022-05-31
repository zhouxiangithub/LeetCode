#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <stack>
#include <unordered_set>

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//递归
class Solution {
public:
    void postorder(const Node* root, vector<int>& res)
    {
        if (root == nullptr)
        {
            return;
        }
        for (auto& ch : root->children)
        {
            postorder(ch, res);
        }
        res.emplace_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};

//迭代
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }

        unordered_map<Node*, int> cnt;
        stack<Node*> st;
        Node* node = root;
        while (!st.empty() || node != nullptr)
        {
            while (node != nullptr)
            {
                st.emplace(node);
                if (node->children.size() > 0)
                {
                    cnt[node] = 0;
                    node = node->children[0];
                }
                else
                {
                    node = nullptr;
                }
            }
            node = st.top();
            int index = cnt.count(node) ? (cnt[node] + 1) : 0;
            if (index < node->children.size())
            {
                cnt[node] = index;
                node = node->children[index];
            }
            else
            {
                res.emplace_back(node->val);
                st.pop();
                cnt.erase(node);
                node = nullptr;
            }
        }
        return res;
    }
};

//迭代：从右到左入栈
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }

        stack<Node*> st;
        unordered_set<Node*> visited;
        st.emplace(root);
        while (!st.empty())
        {
            Node* node = st.top();

            //如果当前节点为叶子节点或者当前节点的子节点已经遍历过
            if (node->children.size() == 0 || visited.count(node))
            {
                res.emplace_back(node->val);
                st.pop();
                continue;
            }

            for (auto it = node->children.rbegin(); it != node->children.rend(); it++)
            {
                st.emplace(*it);
            }
            visited.emplace(node);
        }
        return res;
    }
};