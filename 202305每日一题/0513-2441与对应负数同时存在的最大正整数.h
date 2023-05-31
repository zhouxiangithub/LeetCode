#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0, j = nums.size() - 1; i < j; j--)
        {
            while (i < j && nums[i] < -nums[j])
            {
                i++;
            }
            if (nums[i] == -nums[j])
            {
                return nums[j];
            }
        }
        return -1;
    }
};