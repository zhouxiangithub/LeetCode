#pragma once
using namespace std;
#include <vector>
#include <algorithm>

// m + (m+1) + ... + (m+k-1)
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int m = *max_element(nums.begin(), nums.end());
        return m * k + k * (k - 1) / 2;
    }
};