#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int odd1 = 0, even1 = 0;
        int odd2 = 0, even2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i & 1)
            {
                odd2 += nums[i];
            }
            else
            {
                even2 += nums[i];
            }
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i & 1)
            {
                odd2 -= nums[i];
            }
            else
            {
                even2 -= nums[i];
            }
            if (even1 + odd2 == odd1 + even2)
            {
                res++;
            }
            if (i & 1)
            {
                odd1 += nums[i];
            }
            else
            {
                even1 += nums[i];
            }
        }
        return res;
    }
};