#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long cntZero1 = 0, cntZero2 = 0;
        for (int num : nums1) {
            sum1 += num;
            if (0 == num) {
                sum1++;
                cntZero1++;
            }
        }
        for (int num : nums2) {
            sum2 += num;
            if (0 == num) {
                sum2++;
                cntZero2++;
            }
        }
        if (!cntZero1 && sum1 < sum2 || !cntZero2 && sum2 < sum1) {
            return -1;
        }
        return max(sum1, sum2);
    }
};