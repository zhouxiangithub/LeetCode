#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0, iMax = 0, dMax = 0;
        for (int k = 0; k < n; k++) {
            res = max(res, dMax * nums[k]);
            dMax = max(dMax, iMax - nums[k]);
            iMax = max(iMax, static_cast<long long>(nums[k]));
        }
        return res;
    }
};