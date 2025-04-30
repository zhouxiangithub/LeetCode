#pragma once
using namespace std;
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }

        // dp[i][j] 表示从数组的 [0,i] 中选取若干正整数是否其和等于 j
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        for (int i = 0; i < n; i++) {
            dp[i][0] = true; // 不选
        }
        dp[0][nums[0]] = true; // 选第一个
        for (int i = 1; i < n; i++) {
            int num = nums[i];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};