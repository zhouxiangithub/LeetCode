#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; });

        for (int i = 0; i < n; i++) {
            auto it = lower_bound(events.begin(), events.end(), events[i][0], [](const vector<int>& a, int val) {
                return a[1] < val; });
            int p = distance(events.begin(), it);
            for (int j = 1; j <= k; j++) {
                dp[i + 1][j] = max(dp[i][j], dp[p][j - 1] + events[i][2]);
            }
        }
        return dp[n][k];
    }
};