#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], 2 * edge[2]);
        }

        vector<int> cost(n, INT_MAX);
        vector<bool> visited(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; // cost -- point
        cost[0] = 0;
        q.emplace(0, 0);

        while (!q.empty()) {
            int x = q.top().second;
            q.pop();
            if (x == n - 1) {
                return cost[x];
            }

            if (visited[x]) {
                continue;
            }
            visited[x] = 1;

            for (auto& [y, w] : graph[x]) {
                if (cost[x] + w < cost[y]) {
                    cost[y] = cost[x] + w;
                    q.emplace(cost[y], y);
                }
            }
        }
        return -1;
    }
};