#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
        {
            return 0;
        }
        if (size == 1)
        {
            return nums[0];
        }
        vector<int> dp(size, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
        {
            return 0;
        }
        if (size == 1)
        {
            return nums[0];
        }
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++)
        {
            int tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }
        return second;
    }
};