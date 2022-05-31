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
                C++��׼��ʹ�ñ���vector::push_back�����ຯ��ʱ����Բ����Ķ�����и��ƣ�������Ҳ�Ḵ�ơ�
                ��ͻ���ɶ����ڴ�Ķ��ⴴ��������Ը������Ѳ���push_back��ȥ�����ˣ�ͨ��std::move�����Ա��ⲻ��Ҫ�Ŀ���������
            */
            ans.push_back(move(level));
        }

        return ans;
    }
};
