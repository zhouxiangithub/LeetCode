#pragma once
using namespace std;
#include <vector>

/*
// Definition for a Node.
*/
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

class Solution {
public:
    void preOrder(const Node* root, vector<int>& res)
    {
        if (root == nullptr) 
        {
            return;
        }
        res.emplace_back(root->val);
        for (auto& child : root->children) 
        {
            preOrder(child, res);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }
};