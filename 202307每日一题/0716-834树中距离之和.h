#pragma once
using namespace std;
#include <vector>

/*
    sz[u]表示以u为根的子树的节点数量
    dp[u]表示以u为根的子树,它的所有子节点到它的距离之和
*/
class Solution {
public:
    vector<int> ans, sz, dp;
    vector<vector<int>> graph;

    void dfs(int u, int f)
    {
        sz[u] = 1;
        dp[u] = 0;
        for (auto& v : graph[u])
        {
            if (v == f)
            {
                continue;
            }
            dfs(v, u);
            dp[u] += dp[v] + sz[v];
            sz[u] += sz[v];
        }
    }

    void dfs2(int u, int f)
    {
        ans[u] = dp[u];
        for (auto& v : graph[u])
        {
            if (v == f)
            {
                continue;
            }
            int pu = dp[u], pv = dp[v];
            int su = sz[u], sv = sz[v];

            dp[u] -= dp[v] + sz[v];
            sz[u] -= sz[v];
            dp[v] += dp[u] + sz[u];
            sz[v] += sz[u];

            dfs2(v, u);

            dp[u] = pu, dp[v] = pv;
            sz[u] = su, sz[v] = sv;
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        ans.resize(n, 0);
        sz.resize(n, 0);
        dp.resize(n, 0);
        graph.resize(n, {});
        for (auto& edge : edges)
        {
            int u = edge[0], v = edge[1];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
};