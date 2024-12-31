#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        // first < last : first + (n - 1 - last)
        // first > last : first + (n - 1 - last) - 1
        auto [first, last] = minmax_element(nums.begin(), nums.end());
        return first + nums.size() - 1 - last - (first > last);
    }
};