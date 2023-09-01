#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n); //dp[i]表示以nums[i]结尾的子序列的最小值之和
        vector<int> preSum(n + 1); //dp的前缀和
        int res = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            dp[i] = (nums[i] + preSum[i]) % mod;
            preSum[i + 1] = (preSum[i] + dp[i]) % mod;
            res = (res + (long long)nums[i] * nums[i] % mod * dp[i]) % mod;
            if (res < 0)
            {
                res += mod;
            }
        }
        return res;
    }
};

class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int dp = 0, preSum = 0;
        int res = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            dp = (nums[i] + preSum) % mod;
            preSum = (preSum + dp) % mod;
            res = (res + (long long)nums[i] * nums[i] % mod * dp) % mod;
            if (res < 0)
            {
                res += mod;
            }
        }
        return res;
    }
};