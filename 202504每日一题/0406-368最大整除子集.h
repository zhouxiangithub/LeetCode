#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // 先找出最大子集的个数、最大子集中的最大整数
        vector<int> dp(n, 1); // dp[i] 表示数组升序的情况下, 以 nums[i] 为最大整数的整除子集的大小
        int maxSize = 1;
        int maxValue = dp[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxValue = nums[i];
            }
        }

        // 再倒推获得最大子集
        vector<int> res;
        if (maxSize == 1) {
            res.push_back(nums[0]);
            return res;
        }
        for (int i = n - 1; i >= 0 && maxSize > 0; i--) {
            if (dp[i] == maxSize && maxValue % nums[i] == 0) {
                res.push_back(nums[i]);
                maxValue = nums[i]; // 数组 nums 已是升序
                maxSize--;
            }
        }
        return res;
    }
};