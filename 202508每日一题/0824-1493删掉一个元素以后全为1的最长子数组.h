#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 0;
        int pre = 0, cur = 0;
        for (int num : nums) {
            if (num == 0) {
                cur = pre;
                pre = 0;
            }
            else {
                pre++;
                cur++;
            }
            res = max(res, cur);
        }
        if (res == nums.size()) {
            res--;
        }
        return res;
    }
};