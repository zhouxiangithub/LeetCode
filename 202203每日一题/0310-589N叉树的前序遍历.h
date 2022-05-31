#pragma once
using namespace std;
#include <vector>
#include <stack>

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

//µÝ¹é
class Solution {
public:
    void preorder(const Node* root, vector<int>& res)
    {
        if (root == nullptr)
        {
            return;
        }
        res.emplace_back(root->val);
        for (auto& ch : root->children)
        {
            preorder(ch, res);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};

//µü´ú£º´ÓÓÒÍù×ó
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }

        stack<Node*> st;
        st.emplace(root);
        while (!st.empty())
        {
            Node* node = st.top();
            st.pop();
            res.emplace_back(node->val);
            for (auto it = node->children.rbegin(); it != node->children.rend(); it++)
            {
                st.emplace(*it);
            }
        }
        return res;
    }
};