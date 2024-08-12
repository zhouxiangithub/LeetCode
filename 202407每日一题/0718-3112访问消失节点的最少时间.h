#pragma once
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], len = edge[2];
            adj[u].emplace_back(v, len);
            adj[v].emplace_back(u, len);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, 0);
        vector<int> ans(n, -1);
        ans[0] = 0;
        while (!pq.empty()) {
            auto [time, u] = pq.top();
            pq.pop();
            if (time > ans[u]) {
                continue;
            }
            for (const auto& [v, len] : adj[u]) {
                if (time + len < disappear[v] && (ans[v] == -1 || time + len < ans[v])) {
                    pq.emplace(time + len, v);
                    ans[v] = time + len;
                }
            }
        }
        return ans;
    }
};