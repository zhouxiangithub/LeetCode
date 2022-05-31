#pragma once
using namespace std;
#include <vector>
#include <queue>

/*
    ������Ҷ�ӽڵ�������Ϊmaxdist�����Եõ��Ľ���Ϊ��
    ��С�߶����ĸ߶�Ϊ maxdist/2 ����ȡ����(maxdist+1)/2������С�߶����ĸ��ڵ�һ���������·���ϡ�

    ��ˣ�����ֻ��Ҫ���·���������Ҷ�ӽڵ㼴�ɣ��������·�������м�Ľڵ㼴Ϊ��С�߶����ĸ��ڵ㡣

    1)������ڵ�p���������ù��������������������������ҵ���pΪ�����·�����յ�x��
    2)�Խڵ�x�������ҵ���xΪ�����·�����յ�y��
    3)x��y֮���·����Ϊͼ�е��·�����ҵ�·�����м�ڵ㼴Ϊ���ڵ㡣
*/
class Solution {
public:
    //�����������
    int findLongestNode(int u, vector<int>& parent, vector<vector<int>>& adj)
    {
        int n = adj.size();
        queue<int> qu;
        vector<bool> visit(n);
        qu.emplace(u);
        visit[u] = true;
        int node = -1;

        while (!qu.empty())
        {
            int curr = qu.front();
            qu.pop();
            node = curr;
            for (auto& v : adj[curr])
            {
                if (!visit[v])
                {
                    visit[v] = true;
                    parent[v] = curr;
                    qu.emplace(v);
                }
            }
        }
        return node;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
        {
            return { 0 };
        }
        vector<vector<int>> adj(n);
        for (auto& edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        vector<int> parent(n, -1);
        
        //�ҵ���ڵ�0��Զ�Ľڵ�x
        int x = findLongestNode(0, parent, adj);
        
        //�ҵ���ڵ�x��Զ�Ľڵ�y
        int y = findLongestNode(x, parent, adj);

        //����ڵ�x���ڵ�y��·��
        vector<int> path;
        parent[x] = -1;
        while (y != -1)
        {
            path.emplace_back(y);
            y = parent[y];
        }
        int m = path.size();
        if (m % 2 == 0)
        {
            return { path[m / 2 - 1], path[m / 2] };
        }
        else
        {
            return { path[m / 2] };
        }
    }
};