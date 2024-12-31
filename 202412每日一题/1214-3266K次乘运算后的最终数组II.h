#pragma once
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    long long quickMul(long long x, long long y, long long mod) {
        long long res = 1;
        while (y) {
            if (y & 1) {
                res = (res * x) % mod;
            }
            y >>= 1;
            x = (x * x) % mod;
        }
        return res;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        long long n = nums.size(), mod = 1e9 + 7;
        long long maxValue = *max_element(nums.begin(), nums.end());
        vector<pair<long long, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = { nums[i], i };
        }
        make_heap(v.begin(), v.end(), greater<>());
        for (; v[0].first < maxValue && k; k--) {
            pop_heap(v.begin(), v.end(), greater<>());
            v.back().first *= multiplier;
            push_heap(v.begin(), v.end(), greater<>());
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            int times = k / n + (i < k% n);
            nums[v[i].second] = ((v[i].first % mod) * quickMul(multiplier, times, mod)) % mod;
        }
        return nums;
    }
};