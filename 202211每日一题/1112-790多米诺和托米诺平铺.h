#pragma once
using namespace std;
#include <vector>

//动态规划
const long long mod = 1e9 + 7;
class Solution {
public:
    int numTilings(int n) {
        //dp[i][s]表示平铺到第i列时,各个状态s对应的平铺方法数量
        vector<vector<long long>> dp(n + 1, vector<long long>(4));
        dp[0][3] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = dp[i - 1][3];
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][3] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3]) % mod;
        }
        return dp[n][3];
    }
};