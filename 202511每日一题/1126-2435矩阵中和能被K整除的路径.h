#pragma once
using namespace std;
#include <vector>

class Solution {
private:
    const static int MOD = 1e9 + 7;

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        auto dp = vector(m + 1, vector(n + 1, vector<int>(k)));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j][grid[0][0] % k] = 1;
                    continue;
                }
                int value = grid[i - 1][j - 1] % k;
                for (int remain = 0; remain < k; remain++) {
                    int preRemain = (remain - value + k) % k;
                    dp[i][j][remain] = (dp[i - 1][j][preRemain] + dp[i][j - 1][preRemain]) % MOD;
                }
            }
        }
        return dp[m][n][0];
    }
};