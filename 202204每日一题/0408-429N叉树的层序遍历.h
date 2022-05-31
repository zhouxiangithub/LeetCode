#pragma once
using namespace std;
#include <vector>
#include <queue>

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


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
        {
            return {};
        }

        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            int cnt = q.size();
            vector<int> level;
            for (int i = 0; i < cnt; i++)
            {
                Node* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                for (Node* child : cur->children)
                {
                    q.push(child);
                }
            }
            /*
                C++标准库使用比如vector::push_back等这类函数时，会对参数的对象进行复制，连数据也会复制。
                这就会造成对象内存的额外创建，本来愿意是想把参数push_back进去就行了，通过std::move，可以避免不必要的拷贝操作。
            */
            ans.push_back(move(level));
        }

        return ans;
    }
};
