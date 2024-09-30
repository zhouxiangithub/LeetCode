#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long ans = 1;
        int neg = 0, zer = 0, pos = 0;
        int maxNeg = INT_MIN;
        for (int num : nums) {
            if (num < 0) {
                neg++;
                ans *= num;
                maxNeg = max(maxNeg, num);
            }
            else if (num == 0) {
                zer++;
            }
            else {
                pos++;
                ans *= num;
            }
        }

        if (neg == 1 && zer == 0 && pos == 0) {
            return nums[0];
        }
        if (pos == 0 && neg <= 1) {
            return 0;
        }
        if (ans < 0) {
            return ans / maxNeg;
        }
        else {
            return ans;
        }
    }
};