#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = nums[0];
        int res = 1, cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                maxVal = nums[i];
                res = cnt = 1;
            }
            else if (nums[i] < maxVal) {
                cnt = 0;
            }
            else
            {
                cnt++;
            }
            res = max(res, cnt);
        }
        return res;
    }
};