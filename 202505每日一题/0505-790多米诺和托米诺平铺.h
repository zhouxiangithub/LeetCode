#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    const long long mod = 1e9 + 7;
    int numTilings(int n) {
        // dp[i][s] 表示平铺到第 i 列时各个状态 s 对应的平铺方法数量
        // s-0:无覆盖 1:上覆盖 2:下覆盖 3:全覆盖
        vector<vector<long long>> dp(n + 1, vector<long long>(4));
        dp[0][3] = 1;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i - 1][3];
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        return dp[n][3];
    }
};