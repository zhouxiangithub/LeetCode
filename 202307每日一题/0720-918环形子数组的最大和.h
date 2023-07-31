#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n);
        leftMax[0] = nums[0];
        int leftSum = nums[0];
        int pre = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++)
        {
            pre = max(pre + nums[i], nums[i]);
            res = max(res, pre);
            leftSum += nums[i];
            leftMax[i] = max(leftMax[i - 1], leftSum);
        }
        int rightSum = 0;
        for (int i = n - 1; i > 0; i--)
        {
            rightSum += nums[i];
            res = max(res, rightSum + leftMax[i - 1]);
        }
        return res;
    }
};