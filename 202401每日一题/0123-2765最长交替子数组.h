#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int res = -1;
        int n = nums.size();
        int firstIndex = 0;
        for (int i = 1; i < n; i++)
        {
            int len = i - firstIndex + 1;
            if (nums[i] - nums[firstIndex] == (len - 1) % 2)
            {
                res = max(res, len);
            }
            else
            {
                if (nums[i] - nums[i - 1] == 1)
                {
                    firstIndex = i - 1;
                    res = max(res, 2);
                }
                else
                {
                    firstIndex = i;
                }
            }
        }
        return res;
    }
};