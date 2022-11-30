#pragma once
using namespace std;
#include <vector>

/*
    dp[i][j]表示nums在区间[0,i-1]被切分成j个子数组的最大平均值和,i>=j

    当j>1时,将区间[0,i-1]分成[0,x-1],[x,i-1]两部分
    其中:x-1-0+1>=j-1,即:x>=j-1
    则:dp[i][j]=dp[x][j-1]+(prefix[i]-prefix[x])/(i-x)
*/
class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> prefix(n + 1);
        for (int i = 0; i < n; i++)
        {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<vector<double>> dp(n + 1, vector<double>(k + 1));
        //j=1
        for (int i = 1; i <= n; i++)
        {
            dp[i][1] = prefix[i] / i;
        }
        //j>1
        for (int j = 2; j <= k; j++)
        {
            for (int i = j; i <= n; i++)
            {
                for (int x = j - 1; x < i; x++)
                {
                    dp[i][j] = max(dp[i][j], dp[x][j - 1] + (prefix[i] - prefix[x]) / (i - x));
                }
            }
        }
        return dp[n][k];
    }
};