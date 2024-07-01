#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0, j = 0; j < n; j++) {
            while (nums[j] - nums[i] > 2 * k) {
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};