#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        copy(matrix[0].begin(), matrix[0].end(), dp[0].begin());
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int upValue = dp[i - 1][j];
                if (j > 0)
                {
                    upValue = min(upValue, dp[i - 1][j - 1]);
                }
                if (j < n - 1)
                {
                    upValue = min(upValue, dp[i - 1][j + 1]);
                }
                dp[i][j] = upValue + matrix[i][j];
            }
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};