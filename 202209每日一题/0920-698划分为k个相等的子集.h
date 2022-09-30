#pragma once
using namespace std;
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>

/*
    整数s表示当前可用的数字集合，从低位到高位，第i位为1表示数字nums[i]可用，否则已被使用。
    dp[s]表示在可用的数字状态为s的情况下是否可行。
*/
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k > 0)
        {
            return false;
        }
        int per = sum / k;
        sort(nums.begin(), nums.end());
        if (nums.back() > per)
        {
            return false;
        }
        int n = nums.size();
        vector<bool> dp(1 << n, true);
        function<bool(int, int)> dfs = [&](int s, int p)->bool {
            if (s == 0)
            {
                return true;
            }
            if (!dp[s])
            {
                return dp[s];
            }
            dp[s] = false;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] + p > per)
                {
                    break;
                }
                if ((s >> i) & 1)
                {
                    if (dfs(s ^ (1 << i), (p + nums[i]) % per))
                    {
                        return true;
                    }
                }
            }
            return false;
        };
        return dfs((1 << n) - 1, 0);
    }
};