#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (auto num : nums)
        {
            if (num == 0)
            {
                return 0;
            }
            if (num < 0)
            {
                sign = -sign;
            }
        }
        return sign;
    }
};