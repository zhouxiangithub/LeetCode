#pragma once
using namespace std;
#include <vector>
#include <functional>

/*
    三种状态：0不持有股票，1持有一只股票，2售出一只股票
*/
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> memo(n, vector<vector<long long>>(k + 1, vector<long long>(3, -1)));

        // 第 i 天，进行了 j 笔交易，状态为 state时的最大利润
        function<long long(int, int, int)> dfs = [&](int i, int j, int state)->long long {
            if (j == 0) {
                return 0;
            }
            if (i == 0) {
                return state == 0 ? 0 : (state == 1 ? -prices[0] : prices[0]);
            }
            if (memo[i][j][state] != -1) {
                return memo[i][j][state];
            }

            long long res = 0;
            if (state == 0) {
                res = max(dfs(i - 1, j, 0), max(dfs(i - 1, j, 1) + prices[i], dfs(i - 1, j, 2) - prices[i]));
            }
            else if (state == 1) {
                res = max(dfs(i - 1, j - 1, 0) - prices[i], dfs(i - 1, j, 1));
            }
            else {
                res = max(dfs(i - 1, j - 1, 0) + prices[i], dfs(i - 1, j, 2));
            }
            return memo[i][j][state] = res;
        };

        return dfs(n - 1, k, 0);
    }
};

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<long long>> dp(k + 1, vector<long long>(3));
        
        // i==0
        for (int j = 1; j <= k; j++) {
            dp[j][1] = -prices[0];
            dp[j][2] = prices[0];
        }

        for (int i = 1; i < n; i++) {
            for (int j = k; j > 0; j--) {
                dp[j][0] = max(dp[j][0], max(dp[j][1] + prices[i], dp[j][2] - prices[i]));
                dp[j][1] = max(dp[j - 1][0] - prices[i], dp[j][1]);
                dp[j][2] = max(dp[j - 1][0] + prices[i], dp[j][2]);
            }
        }

        return dp[k][0];
    }
};