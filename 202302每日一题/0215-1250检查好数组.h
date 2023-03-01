#pragma once
using namespace std;
#include <vector>
#include <numeric>

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int divisor = nums[0];
        for (int num : nums)
        {
            divisor = gcd(divisor, num);
            if (divisor == 1)
            {
                return true;
            }
        }
        return false;
    }
};