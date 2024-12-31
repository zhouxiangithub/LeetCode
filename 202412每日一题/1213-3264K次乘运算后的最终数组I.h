#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            auto iter = min_element(nums.begin(), nums.end());
            *iter *= multiplier;
        }
        return nums;
    }
};