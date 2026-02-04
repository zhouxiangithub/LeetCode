#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& num : nums) {
            if (num == 2) {
                num = -1;
            }
            else {
                int t = ~num;
                num ^= (t & -t) >> 1;
            }
        }
        return nums;
    }
};