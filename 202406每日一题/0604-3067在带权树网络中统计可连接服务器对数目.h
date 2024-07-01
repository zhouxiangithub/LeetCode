#pragma once
using namespace std;
#include <vector>
#include <functional>

class Solution {
public:
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size() + 1;
        vector<vector<pair<int, int>>> graph(n);
        
        for (auto edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }

        function<int(int, int, int)> dfs = [&](int p, int root, int cur)->int {
            int res = 0;
            if (cur == 0) {
                res++;
            }
            for (auto& [v, cost] : graph[p]) {
                if (v != root) {
                    res += dfs(v, p, (cur + cost) % signalSpeed);
                }
            }
            return res;
        };

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int pre = 0;
            for (auto& [v, cost] : graph[i]) {
                int cnt = dfs(v, i, cost % signalSpeed);
                ans[i] += pre * cnt;
                pre += cnt;
            }
        }
        return ans;
    }
};