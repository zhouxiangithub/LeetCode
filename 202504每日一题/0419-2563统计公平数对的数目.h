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
            auto right = upper_bound(nums.begin(), nums.begin() + j, upper - nums[j]); // ��һ������
            auto left = lower_bound(nums.begin(), nums.begin() + j, lower - nums[j]); // ��һ����С��
            ans += (right - left); // (right-1)-left+1
        }
        return ans;
    }
};