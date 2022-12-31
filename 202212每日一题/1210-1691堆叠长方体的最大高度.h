#pragma once
using namespace std;
#include <vector>
#include <algorithm>
#include <vector>

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        //将每个长方体的长宽高按照从小到大的顺序排列
        for (auto& v : cuboids)
        {
            sort(v.begin(), v.end());
        }
        sort(cuboids.begin(), cuboids.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] + a[1] + a[2] < b[0] + b[1] + b[2];
            });
        int ans = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
        {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; j++)
            {
                if (cuboids[j][0] <= cuboids[i][0] && cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2])
                {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};