#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> intervals;
        for (int i = 0; i <= n; i++)
        {
            int start = max(0, i - ranges[i]);
            int end = min(n, i + ranges[i]);
            intervals.emplace_back(start, end);
        }
        sort(intervals.begin(), intervals.end());
        vector<int> dp(n + 1, INT_MAX); //dp[i]表示覆盖区间[0,i]所需要的最少的区间数目
        dp[0] = 0;
        for (auto [start, end] : intervals)
        {
            if (dp[start] == INT_MAX)
            {
                return -1;
            }
            for (int j = start; j <= end; j++)
            {
                dp[j] = min(dp[j], dp[start] + 1);
            }
        }
        return dp[n];
    }
};