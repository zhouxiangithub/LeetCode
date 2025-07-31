#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        int maxVal = 0, stateNum = 1 << n;
        for (int i = 0; i < stateNum; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1) {
                    cur |= nums[j];
                }
            }
            if (cur == maxVal) {
                cnt++;
            }
            else if (cur > maxVal) {
                maxVal = cur;
                cnt = 1;
            }
        }
        return cnt;
    }
};