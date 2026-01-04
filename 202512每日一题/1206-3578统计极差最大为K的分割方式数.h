#pragma once
using namespace std;
#include <vector>
#include <set>

class Solution {
private:
    const static int MOD = 1e9 + 7;

public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> dp(n + 1); // dp[i+1]表示以i为结尾的前缀子数组的分割方式数
        vector<long long> preSum(n + 1);
        multiset<int> cnt;
        dp[0] = 1;
        preSum[0] = 1;
        for (int i = 0, j = 0; i < n; i++) {
            cnt.emplace(nums[i]);
            while (j <= i && *cnt.rbegin() - *cnt.begin() > k) {
                cnt.erase(cnt.find(nums[j]));
                j++;
            }
            dp[i + 1] = (preSum[i] - (j > 0 ? preSum[j - 1] : 0) + MOD) % MOD;
            preSum[i + 1] = (preSum[i] + dp[i + 1]) % MOD;
        }
        return dp[n];
    }
};