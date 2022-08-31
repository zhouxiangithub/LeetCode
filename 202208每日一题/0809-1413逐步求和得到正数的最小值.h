#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, sum_min = INT_MAX;
        for (int num : nums)
        {
            sum += num;
            sum_min = min(sum_min, sum);
        }
        return -sum_min + 1 > 0 ? -sum_min + 1 : 1;
    }
};