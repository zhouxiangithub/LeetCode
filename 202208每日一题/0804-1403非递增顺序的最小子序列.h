#pragma once
using namespace std;
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int curr = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            curr += nums[i];
            ans.emplace_back(nums[i]);
            if (curr > sum - curr)
            {
                break;
            }
        }
        return ans;
    }
};