#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ma = 0, mi = 0;
        int maSum = 0, miSum = 0;
        for (int num : nums)
        {
            maSum += num;
            ma = max(ma, maSum);
            maSum = max(maSum, 0);
            miSum += num;
            mi = min(mi, miSum);
            miSum = min(miSum, 0);
        }
        return max(ma, -mi);
    }
};

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, mx = 0, mn = 0;
        for (int num : nums)
        {
            sum += num;
            mx = max(mx, sum);
            mn = min(mn, sum);
        }
        return mx - mn;
    }
};