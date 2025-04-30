#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            auto right = upper_bound(nums.begin(), nums.begin() + j, upper - nums[j]); // 第一个大于
            auto left = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]); // 第一个不小于
            ans += (right - left); // (right-1)-left+1
        }
        return ans;
    }
};