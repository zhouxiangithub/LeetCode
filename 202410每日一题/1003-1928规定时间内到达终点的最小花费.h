#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        // f[t][i] 表示使用恰好 t 分钟到达城市 i 需要的最少通行费总和
        vector<vector<int>> f(maxTime + 1, vector<int>(n, INT_MAX / 2));
        f[0][0] = passingFees[0];
        for (int t = 1; t <= maxTime; t++) {
            for (const auto& edge : edges) {
                int x = edge[0], y = edge[1], time = edge[2];
                if (time <= t) {
                    f[t][x] = min(f[t][x], f[t - time][y] + passingFees[x]);
                    f[t][y] = min(f[t][y], f[t - time][x] + passingFees[y]);
                }
            }
        }

        int ans = INT_MAX;
        for (int t = 1; t <= maxTime; t++) {
            ans = min(ans, f[t][n - 1]);
        }
        return ans == INT_MAX / 2 ? -1 : ans;
    }
};