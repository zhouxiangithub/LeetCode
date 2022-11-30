#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), idx = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                idx = i;
                break;
            }
        }
        if (idx == 0)
        {
            return true;
        }
        for (int i = idx + 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                return false;
            }
        }
        return nums[0] >= nums[n - 1];
    }
};