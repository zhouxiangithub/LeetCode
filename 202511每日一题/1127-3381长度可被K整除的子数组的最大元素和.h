#pragma once
using namespace std;
#include <vector>

/*
    区间[j,i]的子数组和为：preSum[i]-preSum[j-1]
    且 (i-j+1) mod k == 0 即：i mod k == j-1
    找到同余的最小前缀和即可
*/
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long preSum = 0, maxSubSum = LLONG_MIN;
        vector<long long> kSum(k, LLONG_MAX / 2); // 下标同余k的最小前缀和
        kSum[k - 1] = 0; // 下标到k-1则preSum已累加了前k个数
        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            maxSubSum = max(maxSubSum, preSum - kSum[i % k]);
            kSum[i % k] = min(kSum[i % k], preSum);
        }
        return maxSubSum;
    }
};