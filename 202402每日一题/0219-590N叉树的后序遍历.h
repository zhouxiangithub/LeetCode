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
    void postOrder(const Node* root, vector<int>& res)
    {
        if (root == nullptr) 
        {
            return;
        }
        for (auto& child : root->children) 
        {
            postOrder(child, res);
        }
        res.emplace_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> res;
        postOrder(root, res);
        return res;
    }
};