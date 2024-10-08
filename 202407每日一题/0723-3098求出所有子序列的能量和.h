#pragma once
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    using ump = unordered_map<int, int>;
    static constexpr int mod = 1e9 + 7;
    static constexpr int inf = 0x3f3f3f3f;

    int sumOfPowers(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        // d[i][p][v] 表示以 i 为结尾时有多少个长度为 p 且能量为 v 的子序列
        vector<vector<ump>> d(n, vector<ump>(k + 1));
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            d[i][1][inf] = 1;
            for (int j = 0; j < i; j++) {
                int diff = abs(nums[i] - nums[j]);
                for (int p = 2; p <= k; p++) {
                    for (auto& [v, cnt] : d[j][p - 1]) {
                        d[i][p][min(diff, v)] = (d[i][p][min(diff, v)] + cnt) % mod;
                    }
                }
            }

            for (auto& [v, cnt] : d[i][k]) {
                res = (res + 1ll * v * cnt % mod) % mod;
            }
        }
        return res;
    }
};