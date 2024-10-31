#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        double res = numeric_limits<double>::max();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n / 2; i++) {
            res = min(res, (nums[i] + nums[n - 1 - i]) / 2.0);
        }
        return res;
    }
};