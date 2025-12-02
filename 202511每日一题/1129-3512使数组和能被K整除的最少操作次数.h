#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        return accumulate(nums.begin(), nums.end(), 0) % k;
    }
};