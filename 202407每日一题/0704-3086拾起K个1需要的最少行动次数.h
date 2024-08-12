#pragma once
using namespace std;
#include <vector>

class Solution {
public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        int n = nums.size();
        auto f = [&](int i) -> int {
            int x = nums[i];
            if (i - 1 >= 0) {
                x += nums[i - 1];
            }
            if (i + 1 < n) {
                x += nums[i + 1];
            }
            return x;
        };

        vector<long long> indexSum(n + 1), sum(n + 1);
        for (int i = 0; i < n; i++) {
            indexSum[i + 1] = indexSum[i] + nums[i] * i;
            sum[i + 1] = sum[i] + nums[i];
        }
        long long res = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            if (f(i) + maxChanges >= k) {
                if (k <= f(i)) {
                    res = min(res, (long long)k - nums[i]);
                }
                else {
                    res = min(res, (long long)2 * k - f(i) - nums[i]);
                }
                continue;
            }
            int left = 0, right = n;
            while (left <= right) {
                int mid = (left + right) / 2;
                int i1 = max(i - mid, 0), i2 = min(i + mid, n - 1);
                if (sum[i2 + 1] - sum[i1] >= k - maxChanges) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            int i1 = max(i - left, 0), i2 = min(i + left, n - 1);
            if (sum[i2 + 1] - sum[i1] > k - maxChanges) {
                i1++;
            }
            long long count1 = sum[i + 1] - sum[i1], count2 = sum[i2 + 1] - sum[i + 1];
            res = min(res, indexSum[i2 + 1] - indexSum[i + 1] - i * count2 + i * count1 - (indexSum[i + 1] - indexSum[i1]) + 2 * maxChanges);
        }
        return res;
    }
};