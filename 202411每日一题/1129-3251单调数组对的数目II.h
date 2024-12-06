#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] 表示当 arr1[i] = j 时, 前 i + 1 个元素组成的单调数组的数目
        vector<vector<int>> dp(n, vector<int>(1001, 0));
        int mod = 1e9 + 7;

        for (int v = 0; v <= nums[0]; v++) {
            dp[0][v] = 1;
        }

        // v1 <= v2, nums[i-1]-v1 >= nums[i]-v2 ==> v2 >= v1+nums[i]-nums[i-1]
        for (int i = 1; i < n; i++) {
            int d = max(0, nums[i] - nums[i - 1]);
            for (int j = d; j <= nums[i]; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j - d];
                }
                else {
                    dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - d]) % mod;
                }
            }
        }

        int res = 0;
        for (int v : dp[n - 1]) {
            res = (res + v) % mod;
        }
        return res;
    }
};