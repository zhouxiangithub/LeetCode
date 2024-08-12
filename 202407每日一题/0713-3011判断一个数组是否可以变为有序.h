#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int lastCnt = 0;
        int lastMax = 0;
        int curMax = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int curCnt = __builtin_popcount(num);
            if (curCnt == lastCnt) {
                curMax = max(curMax, num);
            }
            else
            {
                lastCnt = curCnt;
                lastMax = curMax;
                curMax = max(curMax, num);
            }

            if (num < lastMax) { //·Ç½µÐò
                return false;
            }
        }
        return true;

    }
};