#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, ans = nums[0];
        for (auto num : nums)
        {
            pre = max(pre + num, num);
            ans = max(ans, pre);
        }
        return ans;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int minPreSum = 0, preSum = 0;
        for (auto num : nums)
        {
            preSum += num;
            ans = max(ans, preSum - minPreSum);
            minPreSum = min(minPreSum, preSum);
        }
        return ans;
    }
};