#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num : nums)
        {
            res ^= num;
        }
        return res;
    }
};