#pragma once
using namespace std;
#include <vector>
#include <numeric>

/*
    left - right = sum - 2*right
*/
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return sum % 2 ? 0 : nums.size() - 1;
    }
};