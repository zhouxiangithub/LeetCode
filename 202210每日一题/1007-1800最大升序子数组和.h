#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0;
        int l = 0;
        while (l < nums.size())
        {
            int cursum = nums[l++];
            while (l < nums.size() && nums[l - 1] < nums[l])
            {
                cursum += nums[l++];
            }
            res = max(res, cursum);
        }
        return res;
    }
};