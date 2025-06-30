#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1, preMin = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] <= preMin) {
                preMin = nums[i];
            } else {
                ans = max(ans, nums[i] - preMin);
            }
        }
        return ans;
    }
};