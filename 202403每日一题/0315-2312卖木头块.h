#pragma once
using namespace std;
#include <vector>
#include <functional>

class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<int>> p(m + 1, vector<int>(n + 1, 0));
        for (auto& v : prices)
        {
            p[v[0]][v[1]] = v[2];
        }

        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, -1));
        function<void(int, int)> dfs = [&](int i, int j) {
            if (dp[i][j] != -1)
            {
                return;
            }
            dp[i][j] = p[i][j];
            for (int x = i / 2; x > 0; x--)
            {
                dfs(x, j);
                dfs(i - x, j);
                dp[i][j] = max(dp[i][j], dp[x][j] + dp[i - x][j]);
            }
            for (int y = j / 2; y > 0; y--)
            {
                dfs(i, y);
                dfs(i, j - y);
                dp[i][j] = max(dp[i][j], dp[i][y] + dp[i][j - y]);
            }
        };

        dfs(m, n);
        return dp[m][n];
    }
};