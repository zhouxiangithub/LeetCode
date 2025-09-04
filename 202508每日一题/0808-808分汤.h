#pragma once
using namespace std;
#include <math.h>
#include <vector>

class Solution {
public:
    double soupServings(int n) {
        n = ceil((double)n / 25);
        if (n >= 179) {
            return 1.0;
        }
        // dp[i][j]表示汤A和汤B分别剩下i和j份时所求的概率值
        // i>0,j=0时dp[i][j]=0
        vector<vector<double>> dp(n + 1, vector<double>(n + 1));
        dp[0][0] = 0.5; // 0.25*(0+4*0.5)=0.5
        for (int i = 1; i <= n; i++) {
            dp[0][i] = 1.0; // 0.25*(4*1+0*0.5)=1.0
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = 0.25 * (dp[max(0, i - 4)][j] + dp[max(0, i - 3)][max(0, j - 1)] +
                    dp[max(0, i - 2)][max(0, j - 2)] + dp[max(0, i - 1)][max(0, j - 3)]);
            }
        }
        return dp[n][n];
    }
};