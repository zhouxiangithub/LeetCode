#pragma once
using namespace std;
#include <string>

class Solution {
public:
    int dp[100001][2];

    int minFlipsMonoIncr(string s) {
        int n = s.size();
        dp[0][0] = dp[0][1] = 0;
        for (int i = 1; i <= n; i++)
        {
            int cur = s[i - 1] - '0';
            dp[i][0] = dp[i - 1][0] + (cur == 0 ? 0 : 1);
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (cur == 1 ? 0 : 1);
        }
        return min(dp[n][0], dp[n][1]);
    }
};