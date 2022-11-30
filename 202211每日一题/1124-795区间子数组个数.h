#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0, idx_l = -1, idx_r = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (left <= nums[i] && nums[i] <= right)
            {
                idx_r = i;
            }
            else if (right < nums[i])
            {
                idx_l = i;
                idx_r = -1;
            }
            if (idx_r != -1)
            {
                res += idx_r - idx_l;
            }
        }
        return res;
    }
};