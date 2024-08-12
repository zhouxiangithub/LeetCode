#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (2 * sum + nums[i] == totalSum) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};