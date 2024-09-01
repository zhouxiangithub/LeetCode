#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> dp(n, 1); //以索引 i 为结尾的最长特殊数组的长度为 dp[i]
        for (int i = 1; i < n; i++) {
            if ((nums[i] ^ nums[i - 1]) & 1) {
                dp[i] = dp[i - 1] + 1;
            }
        }

        vector<bool> res;
        for (auto& query : queries) {
            int x = query[0], y = query[1];
            res.emplace_back(dp[y] >= y - x + 1);
        }
        return res;
    }
};