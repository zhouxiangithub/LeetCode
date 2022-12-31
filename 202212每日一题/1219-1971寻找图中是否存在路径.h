#pragma once
using namespace std;
#include <vector>
#include <queue>

//广度优先搜索
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto&& edge : edges)
        {
            int x = edge[0], y = edge[1];
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        vector<bool> visited(n, false);
        queue<int> qu;
        qu.emplace(source);
        visited[source] = true;
        while (!qu.empty())
        {
            int ver = qu.front();
            qu.pop();
            if (ver == destination)
            {
                break;
            }
            for (int next : adj[ver])
            {
                if (!visited[next])
                {
                    qu.emplace(next);
                    visited[next] = true;
                }
            }
        }
        return visited[destination];
    }
};

//深度优先搜索
class Solution {
public:
    bool dfs(int source, int destination, vector<vector<int>>& adj, vector<bool>& visited)
    {
        if (source == destination)
        {
            return true;
        }
        visited[source] = true;
        for (int next : adj[source])
        {
            if (!visited[next] && dfs(next, destination, adj, visited))
            {
                return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges)
        {
            int x = edge[0], y = edge[1];
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
        }
        vector<bool> visited(n, false);
        return dfs(source, destination, adj, visited);
    }
};