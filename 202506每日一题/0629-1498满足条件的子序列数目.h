#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    static constexpr int MOD = int(1E9) + 7;
    static constexpr int MAX_N = int(1E5) + 5;

    int f[MAX_N];

    // n+1 -> f[n] = 2^n
    void pretreatment() {
        f[0] = 1;
        for (int i = 1; i < MAX_N; ++i) {
            f[i] = (long long)f[i - 1] * 2 % MOD;
        }
    }

    int numSubseq(vector<int>& nums, int target) {
        pretreatment();
        sort(nums.begin(), nums.end());

        int res = 0;
        for (int i = 0; i < nums.size() && nums[i] * 2 <= target; i++) {
            int maxValue = target - nums[i];
            int pos = upper_bound(nums.begin(), nums.end(), maxValue) - nums.begin() - 1;
            int contribute = (pos >= i) ? f[pos - i] : 0; // pos-i+1 -> pos-(i+1)+1=pos-i
            res = (res + contribute) % MOD;
        }
        return res;
    }
};