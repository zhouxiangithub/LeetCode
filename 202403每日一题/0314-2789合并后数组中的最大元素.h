#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long sum = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            sum = nums[i] <= sum ? nums[i] + sum : nums[i];
        }
        return sum;
    }
};