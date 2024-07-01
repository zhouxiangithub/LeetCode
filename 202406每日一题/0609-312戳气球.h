#pragma once
using namespace std;
#include <vector>

class Solution {
private:
    vector<int> val;
    vector<vector<int>> memo;

public:
    int helper(int left, int right) {
        if (left >= right - 1) {
            return 0;
        }
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        for (int i = left + 1; i <= right - 1; i++) {
            int sum = val[left] * val[i] * val[right];
            sum += helper(left, i) + helper(i, right);
            memo[left][right] = max(memo[left][right], sum);
        }
        return memo[left][right];
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        val.resize(n + 2, 1);
        for (int i = 1; i <= n; i++) {
            val[i] = nums[i - 1];
        }
        memo.resize(n + 2, vector<int>(n + 2, -1));
        return helper(0, n + 1);
    }
};