#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366]; // 第i天旅游的情况下,[1,i]这段日子的最小花费
        memset(dp, 0, sizeof(dp));
        int n = days.size();
        dp[0] = 0;
        for (int i = 1, j = 0; i <= 365 && j < n; i++) {
            dp[i] = dp[i - 1]; // 第i天不旅游
            if (i == days[j]) { // 第i天旅游
                dp[i] = dp[max(0, i - 1)] + costs[0];
                dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);
                dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
                j++;
            }
        }
        return dp[days.back()];
    }
};