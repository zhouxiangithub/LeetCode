#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; i++) {
            if (i <= maxPos) {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) {
                    end = maxPos;
                    step++;
                }
            }
        }
        return step;
    }
};