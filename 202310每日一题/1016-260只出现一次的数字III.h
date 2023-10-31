#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x1x2 = 0;
        for (int num : nums)
        {
            x1x2 ^= num;
        }
        int flag = (x1x2 == INT_MIN ? x1x2 : x1x2 & (-x1x2)); //防止溢出,取最低位的1
        int x1 = 0, x2 = 0;
        for (int num : nums)
        {
            if (num & flag)
            {
                x1 ^= num;
            }
            else
            {
                x2 ^= num;
            }
        }
        return { x1,x2 };
    }
};