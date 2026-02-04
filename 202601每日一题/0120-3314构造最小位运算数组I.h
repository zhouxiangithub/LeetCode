#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& num : nums) {
            int res = -1;
            int d = 1;
            while ((num & d) != 0) {
                res = num - d;
                d <<= 1;
            }
            num = res;
        }
        return nums;
    }
};