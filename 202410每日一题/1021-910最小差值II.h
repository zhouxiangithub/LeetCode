#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minNum = nums[0], maxNum = nums.back();
        int res = maxNum - minNum;
        for (int i = 0; i < nums.size() - 1; i++) {
            int a = nums[i], b = nums[i + 1];
            res = min(res, max(a + k, maxNum - k) - min(b - k, minNum + k));
        }
        return res;
    }
};