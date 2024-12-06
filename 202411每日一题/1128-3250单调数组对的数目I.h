#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] 表示当 arr1[i] = j 时, 前 i + 1 个元素组成的单调数组的数目
        vector<vector<int>> dp(n, vector<int>(51, 0));
        int mod = 1e9 + 7;

        for (int v = 0; v <= nums[0]; v++) {
            dp[0][v] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int v2 = 0; v2 <= nums[i]; v2++) {
                for (int v1 = 0; v1 <= v2; v1++) { // arr1 非递减
                    if (nums[i - 1] - v1 >= nums[i] - v2) { // arr2 非递增
                        dp[i][v2] = (dp[i][v2] + dp[i - 1][v1]) % mod;
                    }
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