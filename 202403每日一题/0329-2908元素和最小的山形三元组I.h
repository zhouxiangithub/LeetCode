#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size(), res = 1000;
        vector<int> left(n); //left[i]表示前i个数的最小值
        left[1] = nums[0];
        for (int i = 2; i < n; i++)
        {
            left[i] = min(left[i - 1], nums[i - 1]);
        }
        int right = nums[n - 1];
        for (int i = n - 2; i > 0; i--)
        {
            if (nums[i] > left[i] && nums[i] > right)
            {
                res = min(res, left[i] + nums[i] + right);
            }
            right = min(right, nums[i]);
        }
        return res < 1000 ? res : -1;
    }
};