#pragma once
using namespace std;
#include <vector>
#include <functional>

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int i, int j)->int {
            if (i == 0)
            {
                return grid[i][j];
            }
            if (dp[i][j] >= 0)
            {
                return dp[i][j];
            }
            int res = INT_MAX;
            for (int k = 0; k < n; k++)
            {
                res = min(res, dfs(i - 1, k) + moveCost[grid[i - 1][k]][j] + grid[i][j]);
            }
            dp[i][j] = res;
            return res;
        };
        int res = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            res = min(res, dfs(m - 1, j));
        }
        return res;
    }
};