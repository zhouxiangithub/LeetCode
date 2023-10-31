#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        sort(satisfaction.begin(), satisfaction.end());
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + satisfaction[i - 1] * j;
                if (j < i)
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        int presum = 0, ans = 0;
        for (int si : satisfaction)
        {
            if (presum + si > 0)
            {
                presum += si;
                ans += presum;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};