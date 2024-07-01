#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long res = nums[0];
        //最后移动的元素为偶数/奇数时得分的最大值
        vector<long long> dp(2, INT_MIN);
        dp[nums[0] % 2] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int rem = nums[i] % 2;
            long long cur = max(dp[rem] + nums[i], dp[1 - rem] + nums[i] - x);
            res = max(res, cur);
            dp[rem] = max(dp[rem], cur);
        }
        return res;
    }
};