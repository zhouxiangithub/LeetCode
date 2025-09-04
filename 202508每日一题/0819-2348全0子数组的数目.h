#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int last = -1; // 非0元素的位置
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {
                last = i;
            }
            else {
                res += (i - last);
            }
        }
        return res;
    }
};