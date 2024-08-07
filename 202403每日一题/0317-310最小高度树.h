#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    void dfs(int u, vector<int>& dist, vector<int>& parent, const vector<vector<int>>& adj)
    {
        for (auto& v : adj[u])
        {
            if (dist[v] < 0)
            {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                dfs(v, dist, parent, adj);
            }
        }
    }

    int findLongestNode(int u, vector<int>& parent, const vector<vector<int>>& adj)
    {
        int n = adj.size();
        vector<int> dist(n, -1);
        dist[u] = 0;
        dfs(u, dist, parent, adj);
        int maxdist = 0;
        int node = -1;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] > maxdist)
            {
                maxdist = dist[i];
                node = i;
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
        int x = findLongestNode(0, parent, adj); //找到距离节点0最远的节点x
        int y = findLongestNode(x, parent, adj); //找到距离节点x最远的节点y
        
        //找到节点x到节点y的路径
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
            return { path[m / 2 - 1],path[m / 2] };
        }
        else
        {
            return { path[m / 2] };
        }
    }
};