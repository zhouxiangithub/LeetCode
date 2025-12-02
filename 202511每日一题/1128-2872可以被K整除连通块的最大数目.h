#pragma once
using namespace std;
#include <vector>
#include <functional>

class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int res = 0;
        function<long long(int, int)> dfs = [&](int node, int parent)->long long {
            long long sum = values[node];
            for (int son : graph[node]) {
                if (son != parent) {
                    sum += dfs(son, node);
                }
            }
            if (sum % k == 0) {
                res++;
            }
            return sum;
        };
        dfs(0, -1);
        return res;
    }
};