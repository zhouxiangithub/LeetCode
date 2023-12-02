#pragma once
using namespace std;
#include <queue>

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (!root)
        {
            return nullptr;
        }
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            Node* last = nullptr;
            for (int i = 1; i <= n; i++)
            {
                Node* node = q.front();
                q.pop();
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                if (i != 1)
                {
                    last->next = node;
                }
                last = node;
            }
        }
        return root;
    }
};

class Solution {
public:
    void handle(Node*& last, Node*& p, Node*& nextStart)
    {
        if (last)
        {
            last->next = p;
        }
        if (!nextStart)
        {
            nextStart = p;
        }
        last = p;
    }

    Node* connect(Node* root) {
        if (!root)
        {
            return nullptr;
        }
        Node* start = root;
        while (start)
        {
            Node* last = nullptr, * nextStart = nullptr;
            for (Node* p = start; p != nullptr; p = p->next)
            {
                if (p->left)
                {
                    handle(last, p->left, nextStart);
                }
                if (p->right)
                {
                    handle(last, p->right, nextStart);
                }
            }
            start = nextStart;
        }
        return root;
    }
};