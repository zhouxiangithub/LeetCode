#pragma once
using namespace std;
#include <vector>
#include <functional>

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> g(n);
        for (auto& edge : edges)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        vector<int> isRestricted(n);
        for (auto& point : restricted)
        {
            isRestricted[point] = 1;
        }

        int cnt = 0;
        function<void(int, int)> dfs = [&](int x, int z) {
            cnt++;
            for (auto& y : g[x])
            {
                if (y != z && !isRestricted[y])
                {
                    dfs(y, x);
                }
            }
        };
        dfs(0, -1);
        return cnt;
    }
};