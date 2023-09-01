#pragma once
using namespace std;
#include <vector>

/*
    环状序列相较于普通序列相当于添加了一个限制:普通序列中的第一个和最后一个数不能同时选
    对普通序列进行两遍动态:
        第一遍动态规划中我们删去普通序列中的第一个数,表示我们不会选第一个数
        第二遍动态规划中我们删去普通序列中的最后一个数,表示我们不会选最后一个数
*/
class Solution {
public:
    int calculate(const vector<int>& slices)
    {
        int N = slices.size(), n = (N + 1) / 3;
        vector<vector<int>> dp(N, vector<int>(n + 1, INT_MIN)); //dp[i][j]表示在前i个数中选择了j个不相邻的数的最大和
        dp[0][0] = 0;
        dp[0][1] = slices[0];
        dp[1][0] = 0;
        dp[1][1] = max(slices[0], slices[1]);
        for (int i = 2; i < N; i++)
        {
            dp[i][0] = 0;
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + slices[i]);
            }
        }
        return dp[N - 1][n];
    }

    int maxSizeSlices(vector<int>& slices) {
        vector<int> v1(slices.begin() + 1, slices.end());
        vector<int> v2(slices.begin(), slices.end() - 1);
        int ans1 = calculate(v1);
        int ans2 = calculate(v2);
        return max(ans1, ans2);
    }
};