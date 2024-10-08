#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            res = min(res, nums[i] - nums[i - 1]);
        }
        return res;
    }
};